




#include "StartLine.h"

#if ! defined REQUEST_LINE
#define REQUEST_LINE

class _declspec(dllexport) RequestLine : public StartLine {

private:

	/*
	 * Http request method, The method indicates the method to be 
	 * performed on the resource identified by the Request-URI 
	 * {@link #requestURI}
	 * 
	 * See section 5.1.1 of RFC 2616 for details
	 */
	string method;

	/*
	 * Http request URI, The Request-URI is a Uniform Resource I-
	 * dentifier (section 3.2) and identifies the resource upon 
	 * which to apply the request.
	 * See section 5.1.2 of RFC 2616 for details
	 */
	string requestURI;

	/*
	 * The protocol version of communitions between client and se-
	 * rver base Http. 
	 */
	string protocolVersion;

public:

	RequestLine();

	/**
	 *
	 *
	 */
	RequestLine(string requestURI);

	/**
	 *
	 *
	 */
	RequestLine(string method, string requestURI);

	/**
	 *
	 *
	 */
	RequestLine(string method, string requestURI, string protocolVersion);

	/**
	 * 
	 * 
	 */
	string toTextStream();
};

#endif;