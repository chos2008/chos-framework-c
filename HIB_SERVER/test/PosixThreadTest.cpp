
#include "../posix/PosixThread.hpp"



int main()
{
	PosixThread *thread = new PosixThread();
	thread->start();
}