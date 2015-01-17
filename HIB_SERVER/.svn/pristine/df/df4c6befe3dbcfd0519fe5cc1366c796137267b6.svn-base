DEBUG=../Debug
Release: clean
	g++ -c ../net/socket/SocketException.cpp -o $(DEBUG)/SocketException.o
	g++ -c ../linux/ServerSocket.cpp -o $(DEBUG)/ServerSocket.o
	g++ -c ServerSocketTest.cpp -o $(DEBUG)/ServerSocketTest.o
	g++ $(DEBUG)/*.o -o $(DEBUG)/ServerSocketTest

clean: 
	rm -Rf ./*.bak
	rm -Rf ./*.o
	rm -Rf ./*.obj
	rm -Rf $(DEBUG)/*
	rm -Rf ../*.bak
	rm -Rf ../*.o
	rm -Rf ../*.obj
