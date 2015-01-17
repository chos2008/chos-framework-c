#include <stdio.h>
#include <time.h>
#include <WINSOCK2.H>

void main()
{
	/* void WINAPI GetSystemTime(
	 *     _Out_  LPSYSTEMTIME lpSystemTime
	 * );
	 *
	 * Parameters
	 * lpSystemTime [out]
	 *     A pointer to a SYSTEMTIME structure to receive the current system date and time. The lpSystemTime parameter must not be NULL. Using NULL will result in an access violation.
	 * Return value
	 * This function does not return a value or provide extended error information.
	 * Remarks
	 * To set the current system date and time, use the SetSystemTime function.
	 * 
	 * typedef struct _SYSTEMTIME {
	 *     WORD wYear;
	 *     WORD wMonth;
	 *     WORD wDayOfWeek;
	 *     WORD wDay;
	 *     WORD wHour;
	 *     WORD wMinute;
	 *     WORD wSecond;
	 *     WORD wMilliseconds;
	 * } SYSTEMTIME, *PSYSTEMTIME;
	 */
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	DWORD wYear = stime.wYear;
	DWORD wMonth = stime.wMonth;
	DWORD wDay = stime.wDay;
	DWORD wHour = stime.wHour;
	DWORD wMinute = stime.wMinute;
	DWORD wSecond = stime.wSecond;
	DWORD wMilliseconds = stime.wMilliseconds;
	printf("%04d-%02d-%02d %02d:%02d:%02d.%03d\n", 
		wYear, 
		wMonth, 
		wDay, 
		wHour, 
		wMinute, 
		wSecond, 
		wMilliseconds);

	GetLocalTime(&stime);
	wYear = stime.wYear;
	wMonth = stime.wMonth;
	wDay = stime.wDay;
	wHour = stime.wHour;
	wMinute = stime.wMinute;
	wSecond = stime.wSecond;
	wMilliseconds = stime.wMilliseconds;
	printf("%04d-%02d-%02d %02d:%02d:%02d.%03d\n", 
		wYear, 
		wMonth, 
		wDay, 
		wHour, 
		wMinute, 
		wSecond, 
		wMilliseconds);
	
	time_t t;
	time(&t);
	char* ct = ctime(&t);
	printf("%s Thread starting...\n", ct);

	tm* tt = gmtime(&t);
	char* at = asctime(tt);
	printf("%s Thread starting...\n", at);

	tt = localtime(&t);
	at = asctime(tt);
	printf("%s Thread starting...\n", at);
}