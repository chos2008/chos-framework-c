#include <stdlib.h>
#include "LinkedBarrier.hpp"

LinkedBarrier::LinkedBarrier() 
{
    this->next = NULL;
}

LinkedBarrier::LinkedBarrier(LinkedBarrier* next) 
{
    this->next = next;
}

void LinkedBarrier::setNext(LinkedBarrier* next) 
{
	this->next = next;
}

LinkedBarrier * LinkedBarrier::getNext() 
{
    return this->next;
}