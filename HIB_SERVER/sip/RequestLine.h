/*
 * RFC3261 SPECIFICATION
 * SIP(Session Initiation Protocol)
 *
 */

#include <string>
using namesapce std;

#if ! defined SIP_REQUEST_LINE
#define SIP_REQUEST_LINE

class RequestLine {

public:

	/*
	 * THE SPECIFICATION RFC 3261 FOR SIP(Session Initiation Protocol) 
	 * DEFINES SIX METHODS.
	 *
	 * THERE ARE REGISTER, INVITE, ACK, CANCEL, BYE, OPTIONS.
	 */
	/**
	 * METHOD REGISTER, for registering contact information
	 */
	static const string REGISTER;

	/**
	 *
	 * METHOD INVITE, 
	 */
	static const string INVITE;

	/**
	 * METHOD ACK, 
	 *
	 */
	static const string ACK;

	/**
	 * METHOD CANCEL, for setting up sessions
	 *
	 */
	static const string CANCEL;

	/**
	 * METHOD BYE, for terminating sessions
	 *
	 */
	static const string BYE;

	/**
	 * METHOD OPTIONS, for querying servers about their capabilities.
	 */
	static const string OPTIONS;

public:

	/**
	 *
	 *
	 *
	 */
	RequestLine(string method, string uri);

	/**
	 *
	 *
	 *
	 */
	RequestLine(string method, string uri, string version);

};

#endif;