#include<iostream>  
#include<list>  
#include "CClient.h"  
#pragma comment(lib,"wsock32.lib")  
  
HANDLE hAcceptHandle;  
HANDLE hCleanHandle;  
HANDLE hEvent;  
SOCKET servSocket;  
CRITICAL_SECTION cs;  
bool IsServerRunning;  
std::list<CClient*> clientlist;//�������д洢������������ĸ����ӡ������߳̽�ִ�жԴ��������ɾ��������  
  
bool InitMemember();//��ʼ����Ա������  
bool InitSocket();//��ʼ���׽��֣�����Ϊ������ģʽ���󶨲�������  
bool StartService();//��ʼ���н��տͻ��������̡߳�</span><span style="font-size:18px;">  
bool StopService();//��ֹ���������С�  
DWORD WINAPI CleanThread(void*param);//��Դ�����̡߳�  
DWORD WINAPI AcceptThread(void*param);//���ܿͻ��������̡߳�  
  
  
int main(int argc,char**argv)  
{  
    InitMemember();  
    InitSocket();  
    do  
    {  
        char c;  
        std::cout<<"��ѡ�������"<<std::endl;  
  
        std::cin>>c;  
        if(c=='e')  
        {  
            std::cout<<"�����˳�����������"<<std::endl;  
            StopService();  
        }  
        else if(c=='y')  
        {  
            if(IsServerRunning)  
            {  
                std::cout<<"�������Ѿ��������벻Ҫ�ظ���������"<<std::endl;  
  
            }  
            else  
            {  
                StartService();  
            }  
  
  
        }  
        else if(c=='n')  
        {  
            if(!IsServerRunning)  
            {  
                std::cout<<"������δ�������޷��رգ���"<<std::endl;  
  
            }  
            else  
            {  
                StopService();  
  
            }  
        }  
        else   
        {  
  
        }  
        getchar();  
    }while(IsServerRunning);  
  
    Sleep(3000);  
    WaitForSingleObject(CleanThread,INFINITE);  
  
  
    return 0;  
}  
  
bool InitMemember()  
{  
    std::cout<<"��ʼ��������"<<std::endl;  
  
    IsServerRunning=false;  
    hEvent=NULL;  
    hCleanHandle=NULL;  
    hAcceptHandle=NULL;  
    InitializeCriticalSection(&cs);  
    servSocket=INVALID_SOCKET;  
    return 0;  
}  
  
bool InitSocket()  
{  
    std::cout<<"��ʼ���׽��֡�"<<std::endl;  
  
    WSADATA wsadata;  
    WSAStartup(MAKEWORD(2,2),&wsadata);  
  
    servSocket=socket(AF_INET,SOCK_STREAM,0);  
    if(servSocket==INVALID_SOCKET)  
    {  
        return false;  
    }  
    unsigned long ul=1;  
    int r=ioctlsocket(servSocket,FIONBIO,&ul);  
    if(r==SOCKET_ERROR)  
    {  
        return false;  
    }  
    sockaddr_in addr;  
    addr.sin_addr.S_un.S_addr=INADDR_ANY;  
    addr.sin_family=AF_INET;  
    addr.sin_port=htons(5000);  
    r=bind(servSocket,(sockaddr*)&addr,sizeof(addr));  
    if(r==SOCKET_ERROR)  
    {  
        return false;  
    }  
    int ret=listen(servSocket,10);  
    if(ret==SOCKET_ERROR)  
    {  
        return false;  
    }  
    return true;  
}  
  
bool StartService()  
{  
    std::cout<<"������������"<<std::endl;  
  
    IsServerRunning=true;  
      
    hAcceptHandle=CreateThread(NULL,0,AcceptThread,NULL,0,NULL);  
    if(hAcceptHandle==NULL)  
    {  
        return false;  
    }  
    CloseHandle(hCleanHandle);  
    CloseHandle(hAcceptHandle);  
}  
  
bool StopService()  
{  
    std::cout<<"�رշ�������"<<std::endl;  
    hCleanHandle=CreateThread(NULL,0,CleanThread,NULL,0,NULL);  
    if(hCleanHandle==NULL)  
    {  
        std::cout<<"�����̴߳���ʧ�ܣ�"<<std::endl;  
        return false;  
    }  
    IsServerRunning=false;  
    return 0;  
}  
  
DWORD WINAPI CleanThread( void*param )  
{  
    std::cout<<"��Դ�����߳�������"<<std::endl;  
     //�ж��������ӡ��˳����н��պͷ����߳�ѭ�������߳̽����˳���  
    for(std::list<CClient*>::iterator iter=clientlist.begin();iter!=clientlist.end();iter++)  
    {  
        (*iter)->DisConnect();  
    }  
    Sleep(100);  
    for(iter=clientlist.begin();iter!=clientlist.end();iter++)  
    {  
        delete *iter;  
    }  
    clientlist.clear();  
    SetEvent(hEvent);  
    std::cout<<"��Դ������ϣ���Դ�����߳��˳�����"<<std::endl;  
    return 0;  
}  
  
DWORD WINAPI AcceptThread( void*param )  
{  
    std::cout<<"���ܿͻ��������߳̿�ʼ���С�"<<std::endl;  
  
    while(IsServerRunning)  
    {  
        sockaddr_in addr;  
        SOCKET s;  
        int len=sizeof(addr);  
        s=accept(servSocket,(sockaddr*)&addr,&len);  
        if(s==SOCKET_ERROR)  
        {  
            int r=WSAGetLastError();  
            if(r==WSAEWOULDBLOCK)  
            {  
                //std::cout<<"δ�յ��ͻ��˵���������"<<std::endl;  
  
                Sleep(1000);  
                continue;  
            }  
            else  
            {  
                std::cout<<"δ֪���󣬽��ܿͻ��������߳��˳���"<<std::endl;  
                getchar();  
                return false;  
            }  
        }  
        else//�յ��ͻ�������  
        {  
            std::cout<<"�յ��ͻ��˵���������"<<std::endl;  
  
            CClient*pClient=new CClient(s,addr);  
            pClient->startRunning();//�����ӽ��ܺͷ����߳̿�ʼִ�С�  
            clientlist.push_back(pClient);  
        }  
    }  
    std::cout<<"���ܿͻ��������߳��˳���"<<std::endl;  
  
    return 0;  
}  