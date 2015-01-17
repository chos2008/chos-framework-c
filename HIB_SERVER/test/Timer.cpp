#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//#include <string.h>
#include <string>

//using namespace std;


char* __dateformat(const char* format) {
	time_t t;
	time(&t);
	tm* tt = localtime(&t);
	char* ptr = new char[20];
	strftime(ptr, 20, format, tt);
	return ptr;
}

char* dateformat() 
{
	return __dateformat("%Y-%m-%d %I:%M:%S");
}


char* logdate() 
{
	return dateformat();
}

void log(const char* level, const char* log) 
{
	printf("[%s] %s %s", level, logdate(), log);
}



void logwarn(const char* warn) 
{
	log("WARN", warn);
}

static char msg[] = "time is running out\n";
static int len;
int strength = 32;

// 向标准错误输出信息，告诉用户时间到了
void prompt_info(int signo)
{
    //write(STDERR_FILENO, msg, len);
	strength += 1;
	//char *a = (char *) malloc(sizeof(int));
	//itoa(strength, a, 10);
	//std::string s("Strength ");
	//s = s + std::string(a);
	//char* s = itoa(strength, 
	//logwarn(msg);

	printf("Strength %d \n", strength);
}

// 建立信号处理机制
void init_sigaction(void)
{
    struct sigaction tact;
    /*信号到了要执行的任务处理函数为prompt_info*/
    tact.sa_handler = prompt_info;
    tact.sa_flags = 0;
    /*初始化信号集*/
    sigemptyset(&tact.sa_mask);

    /*建立信号处理机制*/
	/* <sys/signal.h> defines: 
	 * 
	 *     int _EXFUN(sigaction, (int, const struct sigaction *, struct sigaction *));
	 * 
	 * <_ansi.h> defines: 
	 * 
	 *     #define	_EXFUN(name, proto)		__cdecl name proto
	 *     #define	_EXFUN(name, proto)		name proto
	 *     #define	_EXFUN(name, proto)		name()
	 * 
	 * function sigaction defines: 
	 * 
	 *     int __cdecl sigaction (int, const struct sigaction *, struct sigaction *);
	 */
    sigaction(SIGALRM, &tact, NULL);
}

void init_time()
{
    struct itimerval value;
    /*设定执行任务的时间间隔为2秒0微秒*/
    value.it_value.tv_sec = 2;
    value.it_value.tv_usec = 0;
    /*设定初始时间计数也为2秒0微秒*/
    value.it_interval = value.it_value;
    /*设置计时器ITIMER_REAL*/
    setitimer(ITIMER_REAL, &value, NULL);
}
int main()
{
    //len = strlen(msg);
    init_sigaction();
    init_time();
    while ( 1 );
    exit(0);
}