OUTPUT = ../Debug/
Observable_objects = $(OUTPUT)*.o
Release: clean
	g++ -c ../posix/*.cpp 
	mv ./*.o ../Debug
	g++ -c TestPosixMutexLockMessageConsumer.cpp -o ../Debug/TestPosixMutexLockMessageConsumer.o
	g++ -c TestPosixMutexLockMessageProducer.cpp -o ../Debug/TestPosixMutexLockMessageProducer.o
	g++ -c TestPosixMutexLockMessageDestination.cpp -o ../Debug/TestPosixMutexLockMessageDestination.o
	g++ -c PosixMutexLockTest.cpp -o ../Debug/PosixMutexLockTest.o
	g++ $(Observable_objects) -o $(OUTPUT)PosixMutexLockTest

clean:
	rm -Rf ./*.bak
	rm -Rf ./*.o
	rm -Rf ./*.exe
	rm -Rf ../Debug/*