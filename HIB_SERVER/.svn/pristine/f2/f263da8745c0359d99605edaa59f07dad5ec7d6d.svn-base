OUTPUT = ../Debug/
PosixThreadJoinTest_objects = $(OUTPUT)*.o
Release: clean
	g++ -c PosixThreadJoinTest.cpp -o ../Debug/PosixThreadJoinTest.o
#	g++ $(PosixThreadJoinTest_objects) -o $(OUTPUT)PosixThreadJoinTest -L. -lpthreadGC2
	g++ $(PosixThreadJoinTest_objects) -o $(OUTPUT)PosixThreadJoinTest -lpthread

clean:
	rm -Rf ./*.bak
	rm -Rf ./*.o
	rm -Rf ./*.exe
	rm -Rf ../Debug/*