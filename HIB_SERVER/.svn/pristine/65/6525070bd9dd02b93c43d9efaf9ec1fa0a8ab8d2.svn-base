
#include "../../stdafx.h"
#include "stdio.h"

#pragma comment(lib,"ws2_32")

#include <string>
using namespace std;

#include "../../log/log.h"
#include "../../http/RequestLine.h"

int main(int argc, char* argv[]) {

	logdebug("Starting...\n");

	logdebug("Create a start line of http request with method \"GET\", request uri \"/\", protocol version \"1.1\"...\n");
	RequestLine startLine = RequestLine("GET", "/", "1.1");
	
	logdebug("Out put the text stream of http request start line...\n");
	string textStream = startLine.toTextStream();
	printf("[DEBUG] %s %s", logdate(), textStream.c_str());


	logdebug("Create a start line of http request with method \"GET\", request uri \"http://finance.qq.com/stock/?pgv_ref=aio\", protocol version \"1.1\"...\n");
	startLine = RequestLine("GET", "http://finance.qq.com/stock/?pgv_ref=aio", "1.1");
	
	logdebug("Out put the text stream of http request start line...\n");
	textStream = startLine.toTextStream();
	printf("[DEBUG] %s %s", logdate(), textStream.c_str());
	return 1;
}