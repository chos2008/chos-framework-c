
#if ! defined OBJECT
#define OBJECT

template<typename T> 

class _declspec(dllexport) Object {

public:
	T data;

public:
	Object();
};

#endif;