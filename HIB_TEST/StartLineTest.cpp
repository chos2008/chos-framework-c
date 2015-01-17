
#include <stdio.h>
#include <stdlib.h>

#include <string>

using namespace std;

#include "D:\home\admin\workstation\c\dp_d_xml\StartLine.h"
#include "D:\home\admin\workstation\c\HIB_DLog\DLog.h"

void main(int argc, char* argv[]) {
	string* lpStream;
	const char* plStream;

	///*
	// 1
	logdebug("Creating start line...\n");

	StartLine startLine;
	
	lpStream = new string("");
	startLine.toStream(lpStream);
	plStream = (*lpStream).c_str();
	printf("start line stream: %s...\n", plStream);
	//*/

	logdebug("Creating start line...\n");

	StartLine startLine2(new string("1.1"));
	
	lpStream = new string("");
	startLine2.toStream(lpStream);
	plStream = (*lpStream).c_str();
	printf("start line stream: %s...\n", plStream);

	
	///*
	StartLine startLine3(new string("1.2"), new string("utf8"));
	
	lpStream = new string("");
	startLine3.toStream(lpStream);
	plStream = (*lpStream).c_str();
	printf("start line stream: %s...\n", plStream);
	//*/
}