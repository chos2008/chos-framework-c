#ifndef DATA_BUFFER_QUEUE
#define DATA_BUFFER_QUEUE

class DataBufferQueue 
{

private:

	char* data;

	int capacity;

	int size;

public:

	DataBufferQueue();

	DataBufferQueue(int capacity);

	~DataBufferQueue();

	bool enqueue(char c);

	bool enqueue(char *s);

	char element(int i);

	char element();

	void remove(int i);

	char dequeue();

	int size_of();

	bool isEmpty();

	void clear();

	char* toString();

private:

	void initialize(int capacity);

	void ensureCapacity(int minCapacity);
};

#endif;