/*
 *
 *
 *
 *
 */
#include "../collection/LinkedElement.h"
#include "../collection/List.h"
#include "TextMessage.h"

/**
 *
 *
 *
 *
 *
 */
#ifndef HTTP_MESSAGE
#define HTTP_MESSAGE

class _declspec(dllexport) HttpMessage : public TextMessage {

public:

	/**
	 * SP             = <US-ASCII SP, space (32)>
	 * <p>
	 * Space character can represents as character ' ', and it can be 
	 * represented as ascii code <num>32</num> also as it's ascii code
	 * is number <num>32</num>
	 */
	/*_declspec(dllexport) extern */static const char* SP;

	/**
	 * HTTP             = <US-ASCII HTTP, space (?)>
	 * <p>
	 * HTTP character can represents as character 'HTTP', and it can be 
	 * represented as ascii code <num>?</num> also as it's ascii code
	 * is number <num>?</num>
	 */
	static const char* HTTP;

	/**
	 * SLASH             = <US-ASCII SLASH, space (?)>
	 * <p>
	 * Slash character can represents as character '/', and it can be 
	 * represented as ascii code <num>?</num> also as it's ascii code
	 * is number <num>?</num>
	 */
	static const char* SLASH;

	/**
	 * CR             = <US-ASCII CR, carriage return (13)>
	 * <p>
	 * Carriage return character can represents as character '\r', and 
	 * it can be represented as ascii code <num>13</num> also as it's 
	 * ascii code is number <num>13</num>
	 */
	static const char CR; // character '\r' can be also
	
	/**
	 * LF             = <US-ASCII LF, linefeed (10)>
	 * <p>
	 * linefeed character can represents as character '\n', and it can 
	 * be represented as ascii code <num>10</num> also as it's ascii code
	 * is number <num>10</num>
	 */
	static const char LF;

	/**
	 * HTTP/1.1 defines the sequence CR LF as the end-of-line marker for all
   	 * protocol elements except the entity-body (see appendix 19.3 for
   	 * tolerant applications). The end-of-line marker within an entity-body
   	 * is defined by its associated media type, as described in section 3.7.
   	 * <p>
   	 * CRLF           = CR LF
   	 * <p>
	 */
	static const char* CRLF;

public:

	/**
	 *
	 *
	 *
	 */
	string toTextStream();

};

#endif;