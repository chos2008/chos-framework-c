OUTPUT = ../Debug/
PosixMutexLock_objects = $(OUTPUT)*.o
Release: clean
	g++ -c ../posix/*.cpp 
	mv ./*.o ../Debug
	g++ -c PosixMutexLockTest2.cpp -o ../Debug/PosixMutexLockTest2.o
	g++ $(PosixMutexLock_objects) -o $(OUTPUT)PosixMutexLockTest2 -L. -lpthread

clean:
	rm -Rf ./*.bak
	rm -Rf ./*.o
	rm -Rf ./*.exe
	rm -Rf ../Debug/*
#	del /F ./*.bak
#	del /F ./*.o
#	del /F ./*.exe
#	del /F ../Debug/*
