OUTPUT = ../Debug/
Observable_objects = $(OUTPUT)*.o
Release: 
#	g++ -c ../lang/Observable.cpp -o Observable.o
#	g++ -c ObservableTest.cpp -o ObservableTest.o
#	g++ Observable.o ObservableTest.o -o ObservableTest

	rm -Rf ./*.bak
	g++ -c ../lang/*.cpp 
	mv ./*.o ../Debug
	g++ -c ObservableTest.cpp -o ../Debug/ObservableTest.o
	g++ $(Observable_objects) -o $(OUTPUT)ObservableTest

clean:
	rm -Rf ../Debug/*