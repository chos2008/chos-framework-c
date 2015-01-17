#include <time.h> 
#include <stdio.h> 
#include <dos.h> 
int main() 
{ 
	
    time_t timer = NULL; 
    struct tm *tblock = NULL; 


	time_t start_time, rt_start_time;
	struct tm *tm_start_time, *tm_rt_start_time;

    timer=time(NULL); 
    tblock=localtime(&timer); 
	printf("Year[tm->tm_year]: %d\n", tblock->tm_year + 1900);
	printf("Month[tm->tm_mon]: %d\n", tblock->tm_mon + 1);
	printf("Day[tm->tm_mday]: %d\n", tblock->tm_mday);
	printf("Hour[tm->tm_hour]: %d\n", tblock->tm_hour);
	printf("Minute[tm->tm_min]: %d\n", tblock->tm_min);
	printf("Second[tm->tm_sec]: %d\n", tblock->tm_sec);
	printf("Wday[tm->tm_wday]: %d\n", tblock->tm_wday);
	printf("Yday[tm->tm_yday]: %d\n", tblock->tm_yday);	
	printf("Isdst[tm->tm_isdst]: %d\n", tblock->tm_isdst);	
    printf("Local time is: %s\n",asctime(tblock));
	
	
	rt_start_time = time(&start_time); 
	tm_start_time = localtime(&start_time);
	tm_rt_start_time = localtime(&rt_start_time);
	printf("Year[tm->tm_year]: %d\n", tm_start_time->tm_year + 1900);
	printf("Month[tm->tm_mon]: %d\n", tm_start_time->tm_mon + 1);
	printf("Day[tm->tm_mday]: %d\n", tm_start_time->tm_mday);
	printf("Hour[tm->tm_hour]: %d\n", tm_start_time->tm_hour);
	printf("Minute[tm->tm_min]: %d\n", tm_start_time->tm_min);
	printf("Second[tm->tm_sec]: %d\n", tm_start_time->tm_sec);
	printf("Wday[tm->tm_wday]: %d\n", tm_start_time->tm_wday);
	printf("Yday[tm->tm_yday]: %d\n", tm_start_time->tm_yday);	
	printf("Isdst[tm->tm_isdst]: %d\n", tm_start_time->tm_isdst);	
    printf("Local time is: %s\n",asctime(tm_start_time));
	

	
	printf("Year[tm->tm_year]: %d\n", tm_rt_start_time->tm_year + 1900);
	printf("Month[tm->tm_mon]: %d\n", tm_rt_start_time->tm_mon + 1);
	printf("Day[tm->tm_mday]: %d\n", tm_rt_start_time->tm_mday);
	printf("Hour[tm->tm_hour]: %d\n", tm_rt_start_time->tm_hour);
	printf("Minute[tm->tm_min]: %d\n", tm_rt_start_time->tm_min);
	printf("Second[tm->tm_sec]: %d\n", tm_rt_start_time->tm_sec);
	printf("Wday[tm->tm_wday]: %d\n", tm_rt_start_time->tm_wday);
	printf("Yday[tm->tm_yday]: %d\n", tm_rt_start_time->tm_yday);	
	printf("Isdst[tm->tm_isdst]: %d\n", tm_rt_start_time->tm_isdst);	
    printf("Local time is: %s\n",asctime(tm_rt_start_time));
	
    return 0; 
}