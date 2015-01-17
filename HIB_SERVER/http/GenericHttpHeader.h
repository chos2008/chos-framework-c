
#include "HttpHeader.h"

#if ! defined GENERIC_HTTP_HEADER
#define GENERIC_HTTP_HEADER

class _declspec(dllexport) GenericHttpHeader : public HttpHeader {
	
private:

	int size;

public:

	int getSize();
};

#endif;