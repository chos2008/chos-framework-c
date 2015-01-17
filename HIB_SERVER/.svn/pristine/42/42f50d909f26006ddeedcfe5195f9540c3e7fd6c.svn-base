#include <stdio.h>
#include <stdlib.h>

struct zoom 
{
	int id;
	char* name;
	char* ip;
	int port;
};


struct zoomnode 
{
	struct zoom z;
	struct zoomnode *next;
};

typedef struct zoomnode znode, *zoomlink;

zoomlink init(zoomlink head)
{
	if (head == NULL) 
	{
		head = (zoomlink) malloc(sizeof(znode));
	}
	head->next = NULL;
	return head;
}
/*
void main()
{
	//struct zoom nzoom = NULL;

	zoomlink link;
	struct zoom z;

	printf("sizeof(struct zoomnode): %d\n", sizeof(struct zoomnode));
	
	printf("zoomlink link(%ld), zoomlink link point %ld\n", &link, link);
	
	//printf("%d\n", link->z.id); // error, not read

	link = NULL; // note: it must be initialized before access, even NULL.
	link = init(link);

	//link = (zoomlink) malloc(sizeof(znode));

	
	z.id = 1;
	z.name = "华东一区";
	z.ip = "121.11.23.110";
	z.port = 5566;

	printf("sizeof(z): %d\n", sizeof(z));
	printf("Zoom#%d %s from %s:%d\n", z.id, z.name, z.ip, z.port);

	
}
*/