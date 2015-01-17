make:
	g++ -c -D __CYG_WIN UserDTest.cpp -o UserDTest.o
	g++ UserDTest.o -o UserDTest
clear:
	rm UserDTest.o
	rm UserDTest.exe