OUTPUT = ../Debug/
Observable_objects = $(OUTPUT)*.o
Release: clean
	g++ -c ../lang/*.cpp 
	g++ -c ../posix/*.cpp 
	mv ./*.o ../Debug
	g++ -c DestinationXTest.cpp -o ../Debug/DestinationXTest.o
	g++ $(Observable_objects) -o $(OUTPUT)DestinationXTest

clean:
	rm -Rf ./*.bak
	rm -Rf ./*.o
	rm -Rf ../Debug/*