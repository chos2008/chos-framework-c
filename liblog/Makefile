DEBUG=./Debug

make:
	g++ -c log.cpp -o $(DEBUG)/log.o
	ar rcs $(DEBUG)/liblog.a $(DEBUG)/log.o
	g++ -shared -fPIC -o $(DEBUG)/liblog.so $(DEBUG)/log.o
#gcc -shared -fPIC -o liblog.so log.o