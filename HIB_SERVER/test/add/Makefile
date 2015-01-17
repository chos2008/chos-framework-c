main: add.o test_add.o test_main.o 

add.o: add.h
	gcc -c -o add.o add.c
test_add.o: uni_test.h
	gcc -c -o test_add.o test_add.c
test_main.o: 
	gcc -c -o test_main.o test_main.c
	gcc -o test_main add.o test_add.o test_main.o -lcheck