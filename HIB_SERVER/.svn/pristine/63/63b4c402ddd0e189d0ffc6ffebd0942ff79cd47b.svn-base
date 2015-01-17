/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include "hello.h" 
#include "../HttpServer.h"

int main() 
{
	hello("everyone");

	char c1 = '0';
	char c2 = '\0';
	char c3 = 0;
	printf("c1: %d(%c), c2: %d(%c), c3: %d(%c)\n", c1, c1, c2, c2, c3, c3);
	printf("%d(%c) %s %d(%c)\n", c1, c1, c1 == c2 ? "==" : "!=", c2, c2);
	printf("%d(%c) %s %d(%c)\n", c2, c2, c2 == c3 ? "==" : "!=", c3, c3);
	printf("%d(%c) %s %d(%c)\n", c3, c3, c3 == c1 ? "==" : "!=", c1, c1);


	HttpServer *server = new HttpServer();
	server->start();

	return 0; 
}