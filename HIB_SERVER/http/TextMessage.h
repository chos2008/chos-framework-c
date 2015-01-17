
#include <string>
using namespace std;

#include "Message.h"

#ifndef TEXT_MESSAGE
#define TEXT_MESSAGE

class _declspec(dllexport) TextMessage : Message {


public:

	virtual string toTextStream();

};

#endif;