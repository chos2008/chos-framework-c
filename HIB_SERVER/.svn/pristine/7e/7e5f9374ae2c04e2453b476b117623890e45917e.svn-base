OUTPUT = ../Debug/
PosixSpinLock_objects = $(OUTPUT)*.o
Release: clean
	g++ -c ../posix/*.cpp 
	mv ./*.o ../Debug
	g++ -c PosixSpinLockTest.cpp -o ../Debug/PosixSpinLockTest.o
	g++ $(PosixSpinLock_objects) -o $(OUTPUT)PosixSpinLockTest -L. -lpthreadGC2

clean:
	rm -Rf ./*.bak
	rm -Rf ./*.o
	rm -Rf ./*.exe
	rm -Rf ../Debug/*
#	del /F ./*.bak
#	del /F ./*.o
#	del /F ./*.exe
#	del /F ../Debug/*
