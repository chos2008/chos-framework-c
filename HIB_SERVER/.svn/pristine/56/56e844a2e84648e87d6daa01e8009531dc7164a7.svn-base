/**
 * class @Interactive@ provides intertive from std input or output 
 * between std input or output and server
 *
 * method run loops to receive std input and receiv the commands 
 * and input data from std input to process
 * 
 * @author a.da
 * @since 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "net/DataBufferQueue.h"
#include "Interactive.h"
#include "gs/Account.h"

Interactive::Interactive() 
{
	this->command = NULL;
}

/**
 * read string from std input
 * 
 * if new line character '\n' read, return.
 */
char * gets()
{
	DataBufferQueue bf;

	char c;
	while ((c = getchar()) != '\n') // if new line character read
	{
		bf.enqueue(c);
	}
	char *command = bf.toString();
	return command;
}

/**
 * receive command from std input
 * 
 * Return and exit while received the command "exit"
 */
void Interactive::run()
{
	while (1)
	{
		//printf("0: %c(%d), \\n: %c(%d), \\0: %c(%d)\n", 0, 0, '\n', '\n', '\0', '\0');

		printf(">");
		char *command = gets();
		printf("\nCommand: %s\n", command);

		if (strcmp(command, "exit") == 0) 
		{
			if (this->command != NULL) 
			{
				free(this->command);
			}
			break;
		}
		this->shift(command);
	}
}

void Interactive::shift()
{

}

/**
 * shift to the command and process the specific command
 *
 * if the specific command is unknown command that can not be 
 * process, it print "Unknown command @command@!" error info.
 */
void Interactive::shift(char *command)
{
	if (this->command != NULL)
	{
		free(this->command);
	}
	this->command = command;
	if (strcmp(command, "create-account") == 0)
	{
		printf("Enter account id: ");
		char *id = gets();

		printf("Enter account password: ");
		char *password = gets();

		Account account(id, password);
		account.create();
	}
	else 
	{
		fprintf(stderr, "Unknown command %s!\n", command);
	}
}
