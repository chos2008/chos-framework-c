
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

int main(int argc, char* argv[]) {

	logdebug("Starting...\n");

	logdebug("Create a LinkedElement with value \"aaa\"...\n");
	LinkedElement<string>* e = new LinkedElement<string>("aaa");

	logdebug("List:\n");
	LinkedElement<string>* lpElement = e;
	while(lpElement != NULL) {
		logdebug("-- ");
		string data = lpElement->getData();
		printf("%s\n", data.c_str());
		lpElement = lpElement->getNext();
	}

	logdebug("\n");

	logdebug("Create a LinkedElement with value \"bbb\"...\n");
	LinkedElement<string>* e2 = new LinkedElement<string>("bbb");
	
	logdebug("Set \"aaa\" next element value \"bbb\"...\n");
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

	logdebug("Create a LinkedElement with value \"ccc\"...\n");
	LinkedElement<string>* e3 = new LinkedElement<string>("ccc");

	logdebug("Set \"bbb\" next element value \"ccc\"...\n");
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

	logdebug("Create a LinkedElement with value \"ddd\"...\n");
	LinkedElement<string>* e4 = new LinkedElement<string>("ddd");

	logdebug("Set \"ccc\" next element value \"ddd\"...\n");
	e3->setNext(e4);

	logdebug("List:\n");
	lpElement = e;
	while(lpElement != NULL) {
		logdebug("-- ");
		string data = lpElement->getData();
		printf("%s\n", data.c_str());
		lpElement = lpElement->getNext();
	}

	List<string> *list = new List<string>(e);
	
	logdebug("List:\n");
	lpElement = list->getFirst();
	while(lpElement != NULL) {
		logdebug("-- ");
		string data = lpElement->getData();
		printf("%s\n", data.c_str());
		lpElement = lpElement->getNext();
	}

	return 1;
}