// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char *data;
    char a[10],b[10];

    printf("Content-Type:text/html\n\n");
    printf("<HTML>\n");
    printf("<HEAD>\n<TITLE >Get Method</TITLE>\n</HEAD>\n");
    printf("<BODY>\n");
    printf("<div style=\"font-size:12px\">\n");

    data = getenv("QUERY_STRING");
	if (data != NULL) {
        if(sscanf(data,"a=%[^&]&b=%s",a,b)!=2){
            printf("<DIV STYLE=\"COLOR:RED\">Error parameters should be entered!</DIV>\n");
        } else {
            printf("<DIV STYLE=\"COLOR:GREEN; font-size:15px;font-weight:bold\">a + b = %d</DIV>\n",atoi(a)+atoi(b));
        }
	} else {
		printf("QUERY_STRINGΪNULL, û���ύ����!");
	}

    printf("<HR COLOR=\"blue\" align=\"left\" width=\"100\">");
    printf("<input type=\"button\" value=\"Back CGI\" onclick=\"javascript:window.location='../cgi_getquerystring1.html'\">");
    printf("</div>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");
    return 0;
}

