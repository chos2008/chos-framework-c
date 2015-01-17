OUTPUT = ../Debug/
Observable_objects = $(OUTPUT)*.o
Release: clean
	g++ -c ../posix/*.cpp 
	mv ./*.o ../Debug
	g++ -c PosixThreadTest.cpp -o ../Debug/PosixThreadTest.o
	g++ $(Observable_objects) -o $(OUTPUT)PosixThreadTest

clean:
	rm -Rf ./*.bak
	rm -Rf ./*.o
	rm -Rf ./*.exe
	rm -Rf ../Debug/*