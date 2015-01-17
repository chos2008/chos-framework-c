#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <time.h>
#include <signal.h>

#include <windows.h>
#include <mysql.h>

#include <log.h>

#include "Thread.hpp"
#include "MutexLock.hpp"

#include "SQLException.hpp"
#include "Mysql.hpp"
#include "Connection.hpp"
#include "Statement.h"
#include "ResultSet.hpp"

#include "GameServer.h"

#include "net/socket/SocketException.hpp"
#include "net/socket/HardSocket.h"
#include "net/socket/SocketConnectionEventHandler.hpp"
#include "net/socket/SocketConnection.h"

#include "gs/RequestDataBuffer.h"
#include "gs/SocketConnectionHandler.h"
#include "gs/RequestProcessor.h"
#include "gs/Instance.hpp"
#include "gs/InstanceBarrier.hpp"

using namespace std;

class GsWorker : public Thread 
{
private:

	MutexLock *mutex;
	
	SocketConnectionHandler * handler;

	SocketConnection * connection;

public:
	GsWorker() 
	{

	}

	GsWorker(SocketConnection * connection) 
	{
		this->connection = connection;



		// Create a mutex for synchronization
		mutex = new MutexLock();
		//HANDLE m_hMutex = CreateMutex(NULL, FALSE, "DataBufferQueueInstancez#0");

		RequestDataBuffer *requestDataBuffer = new RequestDataBuffer();
		
		/*
		GRequestListener *dataBufferListener 
			= new GRequestListener(mutex);
		requestDataBuffer->registerListener(dataBufferListener);

		dataBufferListener->start();
		*/
		
		SocketConnectionEventHandler *eventHandler = new SocketConnectionEventHandler();

		// create socket connection handler 
		handler = new SocketConnectionHandler(mutex, requestDataBuffer);
		handler->registerEventHandler(eventHandler);
	}

	void run() 
	{
		handler->handle(connection);
	}
};

void GameServer::getBarriers(Instance *instance, char* instance_idx) 
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		throw e;
	}

	Statement *stat = connection->createStatement();


	//string s_idx();
	char *s1 = "select * from global_barrier where instance_index = ";
	int sz = strlen(s1) + strlen(instance_idx) + 1;
	char *sql = (char *) malloc(sz);
	memset(sql, 0, sz);
	strcat(sql, s1);
	strcat(sql, instance_idx);
	
	printf("selecct global barrier: %s\n", sql);
	stat->execute(sql);
	free(sql);
	ResultSet *rs1 = stat->getResultSet();

	int rn = rs1->getRowSize();

	int j = 0;
	while (rs1->next()) 
	{
		char *idx = rs1->get(0);
		char *name = rs1->get(1);
		char *level = rs1->get(2);
		char *instance_idx = rs1->get(3);
		int _idx = atoi(idx);

		InstanceBarrier *barrier = new InstanceBarrier(_idx, name, atoi(level), atoi(instance_idx));
		instance->insert(barrier);
		j++;
	}
}

void displayProgress(int progress)
{
	int k = 0;
	for (k = 0; k < 106; k++)
		putchar('\b');//将当前行全部清空，用以显示最新的进度条状态
	int j = 0;
	for (j = 0; j < progress; j++)
		putchar('+');//打印进度条上已经完成的部分，用‘+’表示
	for (j = 1; j <= 100 - progress; j++)
		putchar('-');//打印进度条上还有多少没有完成的
	fprintf(stdout, "  %3d%%",progress);
	fflush(stdout);
}

int _stat_fs(const char* file) 
{
	FILE* f = fopen(file, "r");

	int size = 0;
    if (f)
    {
		size = filelength(fileno(f));
		fclose(f);
    }
	return size;
}


std::vector<_finddata_t *>* list(const char* file, const char* regex)
{
	int sz = strlen(file) + strlen(regex) + 1;
	char *filename = (char *) malloc(sz);
	memset(filename, 0, sz);
	strcat(filename, file);
	strcat(filename, regex);
	debug("list file %s", filename);

	std::vector<_finddata_t *> *_list = new std::vector<_finddata_t *>();
	struct _finddata_t *FileInfo = NULL;

	long Handle;

	FileInfo = (_finddata_t *) malloc(sizeof(_finddata_t));
	memset(FileInfo, 0, sizeof(_finddata_t));
	if((Handle = _findfirst(filename, FileInfo)) == -1L) 
	{
		return _list;
	}
	else
	{
		_list->push_back(FileInfo);
		
		FileInfo = (_finddata_t *) malloc(sizeof(_finddata_t));
		memset(FileInfo, 0, sizeof(_finddata_t));
		while(_findnext(Handle, FileInfo) == 0) 
		{
			_list->push_back(FileInfo);

			FileInfo = (_finddata_t *) malloc(sizeof(_finddata_t));
			memset(FileInfo, 0, sizeof(_finddata_t));
		}
		_findclose(Handle);
	}
	free(filename);


	return _list;
}

Instance * GameServer::getInstances() throw (SQLException)
{
    Instance *instances = NULL;
	
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		throw e;
	}

	Statement *stat = connection->createStatement();

	string sql = "select * from global_instance";
	stat->execute(sql.c_str());
	ResultSet *rs = stat->getResultSet();
	
	unsigned long rn = rs->getRowSize();
	
	instances = new Instance[rn];
	int i = 0;
	while (rs->next()) 
	{
		char *idx = rs->get(0);

        char *name = rs->get(1);
		
		
		int _idx = atoi(idx);
		Instance *instance = new Instance(1, _idx, name, NULL);


		getBarriers(instance, idx);

		instances[i] = *instance;
		i++;
	}

	mysql->close();
	
	printf("Connection closed\n");


	for (i = 0; i < rn; i++)
	{
		printf("instance %d\t%d\t%s\n", instances[i].getId(), instances[i].getIndex(), instances[i].getName());
		InstanceBarrier* barrier = (InstanceBarrier *)instances[i].getBarrier();
		while (barrier) 
		{
			printf("instance %d barrier %s(%d), level %d\n", barrier->getInstance(), 
				barrier->getName(), barrier->getIdx(), barrier->getLevel());
			barrier = (InstanceBarrier *) barrier->getNext();
		}
	}

	return instances;
}

void GameServer::init() 
{

	Instance * instances = NULL;
	try 
	{
		instances = getInstances();
	}
	catch(SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}

	loginfo("Game server inited\n");
}

void GameServer::startService() 
{
    HardSocket *s = NULL;
	try 
	{
		s = startGameServer();
	}
	catch(SocketException e) 
	{
		error("Fail to start game server, error %d", e.getCode());
		return;
	}

	loginfo("Accepting socket connection...\n");
	while(1) 
	{
		try 
		{
			// accept client connection
			LightSocket* socket = s->accept();
			info("Accepted socket connection from %s:%d", socket->getInetAddressAsString(), socket->getPort());

			GsWorker *worker = new GsWorker(new SocketConnection(socket));
			worker->start();
		}
		catch(SocketException e) 
		{
			error("==================================%d", e.getCode());
			throw e;
		}
	}
	s->close();
	WSACleanup();
}

void dl_data() 
{
	const char* f = "D:\\home\\admin\\workstation\\c\\HIB_SERVER\\data\\";
	const char* regex = "*.xml";
	std::vector<_finddata_t *>* _list = list(f, regex);
	std::vector<_finddata_t *>::iterator it;
	for (it = _list->begin(); it != _list->end(); ++it) 
	{
		string s = string(f) + string((*it)->name);
		int size = _stat_fs(s.c_str());
		debug("Downloading %s, total %d bytes", s.c_str(), size);

		for (int c = 0; c <= 100; c++) 
		{
			displayProgress(c);
			Sleep(500);
		}
		printf("\n");
	}
}

void echo()
{
	char passwd[100];
	memset(passwd, 0, 100);
	int i = 0;
	while (1) 
	{
		char c = getch();
		if (c == '\r' || c == '\n') 
		{
			break;
		}
		passwd[i] = c;
		i++;
	}
	i = 0;

	printf("input string: %s\n", passwd);
}

void GameServer::start() 
{
	init();
	//dl_data();
    startService();
}

HardSocket* GameServer::startGameServer() throw(SocketException) 
{
    HardSocket *socket = new HardSocket();

	int port = 1111;
	socket->bind(port);
	socket->listen();

	/*
	string debug = "Game server listen on 127.0.0.1:";
	//char c[2];
	//sprintf(c, "%d", port);
	char *s = (char *) malloc(sizeof(int));
	s = itoa(port, s, 10);
	//debug += "1111";
	debug.append(s);
	debug += "(default xxxx)...                      [OK]\n";
	loginfo(debug.c_str());
	*/
	info("Game server listen on %s:%d(default 127.0.0.1:1111)", socket->getInetAddressAsString(), socket->getPort());
	return socket;
}