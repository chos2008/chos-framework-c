/*
 * Thread that support cross platform and support global and local start routine, and support 
 * Windows api and C Run-Time Library(even extension) on windows. 
 * <p>
 * To implements a simple thread, only to overrides the run method.
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <windows.h>
#if defined(_WIN32) && defined(_MT)
#include <process.h>
#endif
#include "Runnable.hpp"

#if ! defined THREAD
#define THREAD

// GLOBAL_START_ROUTINE is a user defined macro, likes a switch, to determine whether to 
// select global thread start routine or not. GLOBAL_START_ROUTINE can be defined in program, 
// or using compiler preprocessor options(PREPROCESSOR) /D to define user defined macro 
// GLOBAL_START_ROUTINE to compiles global start routine edition of Thread
#if defined GLOBAL_START_ROUTINE 

#define _GLOBAL_START_ROUTINE
#pragma message ("GLOBAL_START_ROUTINE defined, using global thread start routine.")

// windows
#ifdef _WIN32 
// using compiler linking options /MT to compiles C Run-Time Library(_beginthread, _beginthreadex) 
// edition of Thread
#if defined(_MT) && (! defined(_MT_RT_EX))
#pragma message ("Using C Run-Time Library global thread start routine.")
//#error "C Run-Time Library global thread start routine not supported."
void execute(void *args);
typedef void (* LP_CRT_THREAD_START_ROUTINE)(void *args);

#elif defined(_MT) && defined(_MT_RT_EX)
#pragma message ("Using C Run-Time Library extension global thread start routine.")
//#error "C Run-Time Library extension global thread start routine not supported."
unsigned __stdcall execute(void *args);
typedef unsigned (__stdcall * LP_CRT_EX_THREAD_START_ROUTINE)(void *args);

#else 
DWORD execute(LPVOID args);
#endif

// linux
#else
void* execute(void *args);
#endif

// User defined macro GLOBAL_START_ROUTINE is not specific
// Compiles global start routine edition of Thread using compiler preprocessor options(PREPROCESSOR) /D 
// to define user defined macro GLOBAL_START_ROUTINE
#else 

#pragma message ("GLOBAL_START_ROUTINE not defined, do not using global thread start routine.")
// If GLOBAL_START_ROUTINE not defined, for thread start routine function details, See Thread class 
// declaration when user defined macro defined
#endif

/**
 *
 *
 *
 */
class /*TK_API*/ Thread : public Runnable 
{

private:

#if defined(_WIN32) && defined(_MT)
	unsigned long handle;
#ifdef _MT_RT_EX
	unsigned threadID;
#else
	unsigned long threadID;
#endif
#else

	// handle to a thread
	HANDLE handle;
	DWORD threadID;
#endif

	Runnable *target;

public:

	Thread();

	Thread(const Runnable *runnable);

#if ! defined _GLOBAL_START_ROUTINE
// windows
#ifdef _WIN32 
#if defined(_MT) && (! defined(_MT_RT_EX))
#pragma message ("Using C Run-Time Library global thread start routine.")
#error "C Run-Time Library global thread start routine not supported."
#elif defined(_MT) && defined(_MT_RT_EX)
#pragma message ("Using C Run-Time Library extension global thread start routine.")
#error "C Run-Time Library extension global thread start routine not supported."
#else 
	static DWORD execute(LPVOID args);
#endif
// linux
#else
	static void* execute(void *args);
#endif
#endif
	
	void start();

	virtual void run();

	void join();

};

#endif