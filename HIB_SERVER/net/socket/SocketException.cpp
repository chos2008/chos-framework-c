/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <stdio.h>
#include "SocketException.hpp"

SocketException::SocketException()
{

}

SocketException::SocketException(int code)
{
    this->code = code;
        this->message = NULL;
}

SocketException::SocketException(int code, char* message)
{
    this->code = code;
        this->message = message;
}

int SocketException::getCode()
{
    return this->code;
}

char* SocketException::getMessage()
{
    return this->message;
}


