/*
 *
 *
 *
 */

#include "RequestLine.h"


/**
 *
 *
 */

RequestLine::RequestLine() {

}

RequestLine::RequestLine(string requestURI) {
	this->method = "GET";
	this->requestURI = requestURI;
	this->protocolVersion = "1.1";
}

/**
 *
 *
 */
RequestLine::RequestLine(string method, string requestURI) {
	this->method = method;
	this->requestURI = requestURI;
	this->protocolVersion = "1.1";
}

/**
 *
 *
 */
RequestLine::RequestLine(string method, string requestURI, string protocolVersion) {
	this->method = method;
	this->requestURI = requestURI;
	this->protocolVersion = protocolVersion;
}

/**
 * Example: GET / HTTP/1.1
 * 
 */
string RequestLine::toTextStream() {
	string textStream = "";
	textStream = textStream + this->method;
	textStream = textStream + this->SP;
	textStream = textStream + this->requestURI;
	textStream = textStream + this->SP;
	textStream = textStream + this->HTTP;
	textStream = textStream + this->SLASH;
	textStream = textStream + this->protocolVersion;
	textStream = textStream + this->CRLF;
	return textStream;
}