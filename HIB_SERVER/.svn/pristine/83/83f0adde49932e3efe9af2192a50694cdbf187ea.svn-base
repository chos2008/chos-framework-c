#include <stdio.h>
#include <string>
#include "log.h"
#include "RunMode.h"

using namespace std;

void RunMode::shift()
{
	printf("Enter the mode: ");
	char mode[8];
	gets(mode);
	this->mode = mode;

	string info = "Server is shifting into ";
	info.append(this->mode);
	info.append(" mode");
	loginfo(info.c_str());
}
