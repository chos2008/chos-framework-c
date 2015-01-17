#include <stdio.h>
#include <log.h>
//#include <event.h>

#pragma comment(lib, "D:\\home\\admin\\workstation\\c\\liblog_static\\Debug\\liblog_static.lib")

//#pragma comment(lib, "D:\\usr\\lib\\libevent\\libevent-2.0.11\\libevent-2.0.11\\lib\\libevent_core.lib")
//#pragma comment(lib, "D:\\usr\\lib\\libevent\\libevent-2.0.11\\libevent-2.0.11\\lib\\libevent.lib")
void main()
{
	//const char *version = event_get_version();
    //printf("%s\n",version);

	const char *liblog = "D:\\home\\admin\\workstation\\c\\liblog_static\\Debug\\liblog_static.lib";
	printf("lib %s\n", liblog);

	debug("testt lib %s debug method\n", liblog);


	
    return;
}