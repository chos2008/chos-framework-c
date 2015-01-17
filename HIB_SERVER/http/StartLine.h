


#include "CPPHttpMessage.h"

#if ! defined START_LINE
#define START_LINE

class _declspec(dllexport) StartLine : public HttpMessage {


public:

	//StartLine();

	/**
	 * Method to out put the text stream of {@link StartLine} of 
	 * @b HTTP Message @b. @b HTTP Message @b includes the http 
	 * request that from client to server, and http response that
	 * from server to client.
	 * 
	 * The start line for http request is request line, see 
	 * {@link RequestLine} for details.
	 * The start line for http request is status line, see 
	 * {@link StatusLine} for details.
	 */
	string toTextStream();
};

#endif;