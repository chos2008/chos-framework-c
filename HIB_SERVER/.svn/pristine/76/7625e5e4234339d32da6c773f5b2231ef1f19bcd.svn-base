#include <stdio.h>
#include <winsock2.h>
//#include <windows.h>
#pragma comment(lib,"WS2_32") 

#include "log.h"
#include "../net/socket/Socket.h"

#define WM_SOCKET WM_USER + 1

//-------------------窗口过程---------------------- 
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	debug("process message %d...", uMsg);

    switch(uMsg) 
    {
        case WM_SOCKET: 
        { 
            SOCKET ss = wParam;   //wParam参数标志了网络事件发生的套接口
			debug("Event on socket %d", ss);

			int e = WSAGETSELECTERROR(lParam);
            if (e) 
            {
                closesocket(ss);
				error("select error %d", e);
                return 0; 
            } 
			int event = WSAGETSELECTEVENT(lParam);
			debug("event %d...", event);
            switch (WSAGETSELECTEVENT(lParam)) 
            { 
                case FD_ACCEPT:   //-----①连接请求到来 
                {
                    sockaddr_in Cadd; 
                    int Cadd_len = sizeof(Cadd); 
                    SOCKET sNew = accept(ss, (sockaddr *) &Cadd, &Cadd_len); 
                    if (sNew == INVALID_SOCKET) 
					{
						int error = WSAGetLastError();
                        warn("fail to accept request, error %d", error);
						return 0;
                    }
					
					char* c = (char *) malloc(sizeof(Cadd.sin_port));
					itoa(Cadd.sin_port, c, 10);

					debug("Accepted socket %d connection from %s:%s", sNew, inet_ntoa(Cadd.sin_addr), c);
					WSAAsyncSelect(sNew, hwnd, WM_SOCKET, FD_READ | FD_CLOSE); 
                }
				break; 
                case FD_READ:   //-----②数据发送来 
                {
					debug("Reading from socket %d...", ss);
                    char cbuf[256];
                    memset(cbuf, 0, 256);
                    int bytes = recv(ss, cbuf, 256, 0);
					if (bytes == SOCKET_ERROR) 
					{
						int error = WSAGetLastError();
						warn("fail to receive data, error %d", error);
						if (error == WSAEWOULDBLOCK) 
						{
						    warn("fail to receive data, error WSAEWOULDBLOCK(%d)", error);
						} 
						else 
						{
							if (error == WSAECONNRESET) 
							{
								warn("fail to receive data, error WSAECONNRESET(%d)", error);
							}
							return 0;
						}
					}
                    if (bytes == 0) 
                    {
                        closesocket(ss);
						warn("调用recv()失败！");
						return 0;
                    } 
                    else if (bytes>0) 
                    {
                        info("收到的信息: %s", cbuf);

                        char Sbuf[]="Hello client!I am server"; 
                        int isend = send(ss, Sbuf, sizeof(Sbuf), 0); 
                        if (isend == SOCKET_ERROR || isend <= 0) 
                        { 
                            warn("发送消息失败！");                             
                        } 
                        else 
						{
                            info("已经发信息到客户端！");
						}
                    } 
                }
				break; 
                case FD_CLOSE:    //----③关闭连接 
				{
                    closesocket(ss); 
					debug("Socket %d closed", ss);
                } 
                break; 
			}
        }
        break; 
        case WM_CLOSE: 
            if (IDYES==MessageBox(hwnd,"是否确定退出？","message",MB_YESNO)) 
			{
                DestroyWindow(hwnd);
			}
            break; 
        case WM_DESTROY: 
            PostQuitMessage(0); 
            break; 
        default: 
            return DefWindowProc(hwnd,uMsg,wParam,lParam); 
	}
    return 0; 
}

void main()
{
	WSADATA wsd;
    SOCKET Listen;
    SOCKADDR_IN InternetAddr;

    // 初始化Windows Socket 2.2
	WSAStartup(MAKEWORD(2,2), &wsd);
 
	// 创建监听Socket
    Listen = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	info("Server socket %d", Listen);
 
    // 设置服务器地址
    InternetAddr.sin_family = AF_INET;
    InternetAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int port = 5150;
    InternetAddr.sin_port = htons(port);
 
    // 绑定Socket
    bind(Listen, (PSOCKADDR) &InternetAddr, sizeof(InternetAddr));

	// 开始监听
    listen(Listen, 5);
    info("listen on %s:%d(%s:%d)", inet_ntoa(InternetAddr.sin_addr), port, 
		inet_ntoa(InternetAddr.sin_addr), htons(port));


	HWND Window;

	HINSTANCE hInstance = GetModuleHandle(NULL);

	WNDCLASS wc; 
    wc.style=CS_HREDRAW|CS_VREDRAW; 
    wc.lpfnWndProc=WindowProc;
    wc.cbClsExtra=0; 
    wc.cbWndExtra=0; 
    wc.hInstance=hInstance; 
    wc.hIcon=LoadIcon(NULL,IDI_EXCLAMATION); 
    wc.hCursor=LoadCursor(NULL,IDC_ARROW); 
    wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH); 
    wc.lpszMenuName=NULL; 
    wc.lpszClassName="Test"; 
    //---注册窗口类---- 
    RegisterClass(&wc);

	

    // 创建主窗口
    Window = CreateWindow("Test", 
		"窗口标题", 
		WS_SYSMENU, 
		300, 
		0, 
		600, 
		400, 
		NULL, 
		NULL, 
		hInstance, 
		NULL);
	if (Window == NULL) 
	{
		DWORD error = GetLastError();
		warn("error %d\n", error);
		return;
	}
	debug("Window %s to accept socket message created", "Test");
    // 设置Windows消息，这样当有Socket事件发生时，窗口就能收到对应的消息通知
	// 服务器一般设置 FD_ACCEPT │ FD_READ | FD_CLOSE
	// 客户端一般设置 FD_CONNECT │ FD_READ | FD_CLOSE
	debug("WM_SOCKET(%d)", WM_SOCKET);
	debug("FD_ACCEPT(%d)", FD_ACCEPT);
	debug("FD_READ(%d)", FD_READ);
	debug("FD_CLOSE(%d)", FD_CLOSE);
    int error = WSAAsyncSelect(Listen, Window, WM_SOCKET, FD_ACCEPT | FD_READ | FD_CLOSE);
    if (error == SOCKET_ERROR) 
	{
	    error = WSAGetLastError();
		warn("error %d", error);
		return;
	}

	//---消息循环---- 
    MSG msg; 
    while (GetMessage(&msg,0,0,0)) 
    { 
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    } 
    closesocket(Listen); 
    WSACleanup(); 
    //ShowWindow(Window, SW_SHOWNORMAL);
    ExitThread(0);
}