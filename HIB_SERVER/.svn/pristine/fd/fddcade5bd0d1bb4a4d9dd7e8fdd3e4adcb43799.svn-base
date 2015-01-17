#pragma comment(lib,"ws2_32.lib") 

#include <stdio.h>
#include <string.h>
#include <WINSOCK2.H>

#include <log.h>
#include "Select.hpp"


Select::Select(HardSocket &socket) 
{
	this->socket = &socket;
	//Socket::init(AF_INET, SOCK_STREAM, 0);
	FD_ZERO(&fd);
	FD_SET(this->socket->getPlainSocket(), &fd);
}

void Select::registerSelectEventHandler(SelectEventHandler &eventHandler) 
{
	this->eventHandler = &eventHandler;
}

void Select::select()
{
	fd_set fdOld = fd;
	//timeval tm;
	//tm.tv_sec = 0;
	//tm.tv_usec = 1000;
    int selected = ::select(0, &fdOld, NULL, NULL, NULL);  
        
	if (selected == SOCKET_ERROR)  
    {  
        //WSACleanup();   
		//printf("Faild to select sockt in server!/r/n");  
        int error = WSAGetLastError();
		warn("select error %d", error);
		Sleep(100);  
    }
	else if (selected == 0) 
	{
		warn("select error, time limit expired");
	}
	else 
    {
        for(int i = 0;i < fd.fd_count; i++) 
        {
			SOCKET sfd = fd.fd_array[i];
            if (FD_ISSET(sfd, &fdOld)) 
            {
                //如果socket是服务器，则接收连接
                if (sfd == socket->getPlainSocket()) 
				{
					onAccept();
                }
                else //非服务器,接收数据(因为fd是读数据集)
                {
					onRead(sfd);
                }
            }
			else 
			{
				warn("socket fd %d not in fd set", sfd);
			}
        }
    }
}

void Select::onAccept() 
{
	sockaddr_in addrAccept;
    int so_sockaddr_in = sizeof(sockaddr_in);
	memset(&addrAccept, 0, so_sockaddr_in);


    SOCKET sockAccept = ::accept(socket->getPlainSocket(), (sockaddr *) &addrAccept, &so_sockaddr_in);  
    if (sockAccept == INVALID_SOCKET) 
    {
	    warn("accepted an invalid socket connection");
		return;
	}
    FD_SET(sockAccept, &fd);
    //FD_SET(sockAccept,&fdOld);
    info("%s:%d has connected server!", inet_ntoa(addrAccept.sin_addr), ntohs(addrAccept.sin_port));

	LightSocket *cs = new LightSocket(sockAccept);
	cs->setSocketAddress(addrAccept);
	eventHandler->onAccept(*cs);
}

void Select::onRead(SOCKET sfd) 
{
	char szDataBuff[100];///////
    memset(szDataBuff, 0, 100);
	szDataBuff[100 - 1] = '\0';

    int bytes = recv(sfd, szDataBuff, 100 - 1, 0);
        
	sockaddr_in addr;
	int so_sockaddr_in = sizeof(sockaddr_in);
	memset(&addr, 0, so_sockaddr_in);
    getpeername(sfd, (sockaddr *) &addr, &so_sockaddr_in);
    if (bytes == SOCKET_ERROR)  
    {
		int error = WSAGetLastError();
        warn("Fail to receive data from %s:%d error %d", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), error);
		closesocket(sfd);
        FD_CLR(sfd, &fd);
        //i--;
        return;
    }

    if (bytes == 0) 
    {
        //客户socket关闭  
        warn("%s:%d has closed!", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

        closesocket(sfd);
        FD_CLR(sfd, &fd);
        //i--;
    }  
          
    if (bytes > 0) 
    {
		LightSocket *cs = new LightSocket(sfd);
		cs->setSocketAddress(addr);
		eventHandler->onMessage(*cs, szDataBuff);
    }
}
