//�����߳�ͬ������ ������Mutex  
#include <stdio.h>  
#include <process.h>  
#include <windows.h>  
#include <assert.h>
      
long g_nNum;  
    
//unsigned int __stdcall Fun(void *pPM);  
DWORD WINAPI Fun(LPVOID args);
	
const int THREAD_NUM = 10;  
//��������ؼ���  
HANDLE  g_hThreadParameter;  
CRITICAL_SECTION g_csThreadCode;  
     
int main()  
{  
	printf("     �����߳�ͬ�� ������Mutex\n");  
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");  
         
	//��ʼ����������ؼ��� �ڶ�������ΪTRUE��ʾ������Ϊ�����߳�����  
	g_hThreadParameter = CreateMutex(NULL, FALSE, NULL);  
	InitializeCriticalSection(&g_csThreadCode);  

	HANDLE  handle[THREAD_NUM];   
	g_nNum = 0;
	int i = 0;
	while (i < THREAD_NUM)
	{
		DWORD threadID;
		//handle[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, &i, 0, NULL); 
		handle[i] = CreateThread(NULL, 0, Fun, &i, 0, &threadID);
		//CreateThread(NULL, 0, ModuleEcho, (LPVOID) NULL, 0, &threadID);
		//assert(handle[i] == threadID);

		WaitForSingleObject(g_hThreadParameter, INFINITE); //�ȴ�������������  
		i++;
	}
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);

	//���ٻ������͹ؼ���
	CloseHandle(g_hThreadParameter);
	DeleteCriticalSection(&g_csThreadCode);
	for (i = 0; i < THREAD_NUM; i++)
		CloseHandle(handle[i]);
	return 0;
}

DWORD WINAPI Fun(LPVOID args)
//unsigned int __stdcall Fun(void *pPM) 
{
	//int nThreadNum = *(int *)pPM;  
	int nThreadNum = (int) args;
	ReleaseMutex(g_hThreadParameter);//����������  

	Sleep(50);//some work should to do  

	EnterCriticalSection(&g_csThreadCode);  
	g_nNum++;  
	Sleep(0);//some work should to do  
	printf("�̱߳��Ϊ%d  ȫ����ԴֵΪ%d\n", nThreadNum, g_nNum);  
	LeaveCriticalSection(&g_csThreadCode);  
	return 0;  
}  