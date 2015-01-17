#include <stdio.h>
#include "../ObjectModule.hpp"

void method() {
    printf("method called!\n");
}
int main(int argc, char *args) 
{
    ObjectModule *module = new ObjectModule("module", NULL, method);
	module->start();
}