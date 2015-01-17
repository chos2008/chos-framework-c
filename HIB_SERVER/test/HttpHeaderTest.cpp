
#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include "WINSOCK2.H"
#include "time.h"
#include <assert.h>

#pragma comment(lib,"ws2_32")

#include <string>
using namespace std;

#include "log.h"
#include "LinkedElement.h"
#include "LinkedElement.cpp"
#include "List.h"
#include "List.cpp"

#include "HttpHeader.h"

int main(int argc, char* argv[]) {

	logdebug("Starting...\n");

	logdebug("Create a LinkedElement with value \"GB2312\"...\n");
	LinkedElement<string>* e = new LinkedElement<string>("GB2312");

	logdebug("List:\n");
	LinkedElement<string>* lpElement = e;
	while(lpElement != NULL) {
		logdebug("-- ");
		string data = lpElement->getData();
		printf("%s\n", data.c_str());
		lpElement = lpElement->getNext();
	}

	logdebug("\n");

	logdebug("Create a LinkedElement with value \"utf-8;q=0.7\"...\n");
	LinkedElement<string>* e2 = new LinkedElement<string>("utf-8;q=0.7");
	
	logdebug("Set \"GB2312\" next element value \"utf-8;q=0.7\"...\n");
	e->setNext(e2);

	logdebug("List:\n");
	lpElement = e;
	while(lpElement != NULL) {
		logdebug("-- ");
		string data = lpElement->getData();
		printf("%s\n", data.c_str());
		lpElement = lpElement->getNext();
	}

	logdebug("\n");

	logdebug("Create a LinkedElement with value \"*;q=0.7\"...\n");
	LinkedElement<string>* e3 = new LinkedElement<string>("*;q=0.7");

	logdebug("Set \"utf-8;q=0.7\" next element value \"*;q=0.7\"...\n");
	e2->setNext(e3);

	logdebug("List:\n");
	lpElement = e;
	while(lpElement != NULL) {
		logdebug("-- ");
		string data = lpElement->getData();
		printf("%s\n", data.c_str());
		lpElement = lpElement->getNext();
	}

	logdebug("\n");

	List<string> *list = new List<string>(e);
	
	logdebug("List:\n");
	lpElement = list->getFirst();
	while(lpElement != NULL) {
		logdebug("-- ");
		string data = lpElement->getData();
		printf("%s\n", data.c_str());
		lpElement = lpElement->getNext();
	}

	HttpHeader header = HttpHeader("Accept-Charset", list);
	string textstream = header.toTextStream();
	printf("%s\n", textstream.c_str());

	header = HttpHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
	textstream = header.toTextStream();
	printf("%s\n", textstream.c_str());

	header = HttpHeader("Accept", NULL);
	textstream = header.toTextStream();
	printf("%s\n", textstream.c_str());

	header = HttpHeader("User-Agent", "Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.1.2) Gecko/20090729 Firefox/3.5.2");
	textstream = header.toTextStream();
	printf("%s\n", textstream.c_str());

	return 1;
}