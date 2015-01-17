#include <stdio.h>
#include <stdlib.h>
#include "../lang/DestinationMessage.hpp"
#include "../lang/DestinationX.hpp"

class DestinationMessageImpl : public DestinationMessage
{
private:
	char *content;

public:
	DestinationMessageImpl(char *content) 
	{
		this->content = content;
	}

	void* getContent() 
	{
		return (void *) this->content;
	}
};

void testDe(DestinationX &dest)
{
	int message = dest.de();
	printf("message %d\n", message);
	/*
	if (message == NULL)
	{
		printf("Message NULL\n");
	}
	else 
	{
		printf("Message not NULL\n");
	}
	*/
}

void testEn(DestinationX &dest) 
{
	//DestinationMessage *new_message = new DestinationMessageImpl("new message");
	dest.en(1);

	int message = dest.de();
	printf("message %d\n", message);
	/*
	if (message == NULL)
	{
		printf("Message NULL\n");
	}
	else 
	{
		printf("Message not NULL\n");
		char *content = (char *) message->getContent();
		printf("Message content %s\n", content);
	}
	*/
}

int main()
{
	printf("Test Destination\n");
	DestinationX dest("1");
	printf("destination id %s\n", dest.getId());
	testDe(dest);
	testEn(dest);

	std::queue<int> q;
	printf("size of %d\n", q.size());
	for (int i = 1; i <= 10; i++)
	{
		q.push(i);
		printf("size of %d\n", q.size());
	}
	while(! q.empty())
	{
		printf("%d\t", q.front());
		q.pop();
	}
	printf("\n");

}