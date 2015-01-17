#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WINDOWS.H>
#include "DataBufferQueue.h"

DataBufferQueue::DataBufferQueue()
{
	this->initialize(16);
}

DataBufferQueue::DataBufferQueue(int capacity)
{
	this->initialize(capacity);
}

DataBufferQueue::~DataBufferQueue()
{
	free(this->data);
}

void DataBufferQueue::initialize(int capacity)
{
	if (capacity < 0)
	{
		throw capacity;
	}
	
	this->capacity = capacity;
	this->data = (char *) malloc(capacity * sizeof(char));
	memset(this->data, 0, capacity);
	this->size = 0;

}

int DataBufferQueue::size_of()
{
	return this->size;
}

bool DataBufferQueue::isEmpty() 
{
	return this->size == 0;
}

void DataBufferQueue::clear()
{
	this->size = 0;
	memset(this->data, 0, this->capacity);
}

void DataBufferQueue::ensureCapacity(int minCapacity)
{
	if (minCapacity > this->capacity) 
	{
		int newCapacity = (this->capacity * 3)/2 + 1;
		if (newCapacity < minCapacity) 
		{
			newCapacity = minCapacity;
		}
		this->capacity = newCapacity;

		// 
		this->data = (char *) realloc(this->data, newCapacity);
		char * p = &this->data[this->size];
		memset(p, 0, this->capacity - this->size);
		

	}
}

bool DataBufferQueue::enqueue(char c)
{
	ensureCapacity(this->size + 1);
	this->data[this->size] = c;
	this->size++;
	return true;
}

bool DataBufferQueue::enqueue(char *s)
{
	char *p = s;
	while(*p) 
	{
		enqueue(*p++);
	}
	return true;
}

char DataBufferQueue::element(int i) 
{
	if (i < 0) 
	{
		return NULL;
	}
	if (i >= this->size) 
	{
		return NULL;
	}
	char c = this->data[i];
	return c;
}

char DataBufferQueue::element()
{
	return element(0);
}

void DataBufferQueue::remove(int i) 
{
	if (i < 0) 
	{
		return;
	}
	if (i >= this->size) 
	{
		return;
	}
	
	for (int t = i + 1; i < this->size; i++)
	{
		this->data[t - 1] = this->data[t];
	}
	this->data[t] = '\0';
}

char DataBufferQueue::dequeue()
{
	char c = this->element();
	if (c != NULL) 
	{
		char* temp = (char *) malloc(this->capacity -1);
		memset(temp, 0, this->capacity - 1);

		char* newData = this->data;//&this->data[this->size - 1];
		*newData++;
		memcpy(temp, newData, this->capacity - 1);

		free(this->data);
		this->data = temp;
		this->size--;
	}
	return c;
}

char* DataBufferQueue::toString()
{
	/*
	if (this->size == 0) 
	{
		return NULL;
	}
	return this->data;
	*/
	
	char *s = NULL;
	if (this->size == 0)
	{
		return s;
	}
	s = (char *) malloc((this->size + 1) * sizeof(char));
	memset(s, 0, (this->size + 1) * sizeof(char));
	memcpy(s, this->data, this->size * sizeof(char));
	return s;
}