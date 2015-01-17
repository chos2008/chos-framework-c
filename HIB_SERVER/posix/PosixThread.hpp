/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <pthread.h>
#include "../Runnable.hpp"

//#define GLOBAL_START_ROUTINE

#if ! defined POSIX_THREAD
#define POSIX_THREAD

// On linux and linux like system, the start routine function defined
//
//     void *(*start_routine)(void*)
//
// And on windows system, 
//
// The LPTHREAD_START_ROUTINE type defines a pointer to this callback function. 
// ThreadProc is a placeholder for the application-defined function name.
// 
// typedef DWORD (__stdcall *LPTHREAD_START_ROUTINE) (
//     [in] LPVOID lpThreadParameter
// );
//
// Function prototype: 
// 
// DWORD WINAPI ThreadProc(
//     _In_  LPVOID lpParameter
// );
//
#if defined GLOBAL_START_ROUTINE 
#define _GLOBAL_START_ROUTINE 

#ifdef _WIN32 
DWORD __stdcall execute(LPVOID args);
#else
void* execute(void *args);
#endif

#endif


#ifndef _WIN32
typedef void* (*PTHREAD_START_ROUTINE)(void *args);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
#endif

class PosixThread : public Runnable
{
	private:
		pthread_t pthread;

		int atf;

		pthread_attr_t attr;

	public: 
		PosixThread();

		PosixThread(int stackSize);

#if ! defined _GLOBAL_START_ROUTINE 
		static void* execute(void *args);
#endif
		void start();

		virtual void run();

		pthread_t& getId();
};
#endif