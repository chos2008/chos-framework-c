# 
# On Unix¡¢Unix likes¡¢Linux system, command line: 
#     gcc -dM -E - < /dev/null 
# can print infos about precompile defines
# 
# @author ada
# @version 1.0
#mod_actor: gs/Actor.h 
#	g++ -c -o Debug/Actor.o gs/Actor.cpp


module: mod_game_engine mod_log mod_server server test

mod_game_engine: mod_endpoint mod_actor 
mod_actor: Debug/Actor.o
mod_endpoint: Debug/gs/ServerEndpoint.o


Debug/Actor.o: gs/Actor.h
	g++ -c -o Debug/Actor.o gs/Actor.cpp

Debug/gs/ServerEndpoint.o: Debug/gs gs/ServerEndpoint.h
	g++ -c -o Debug/gs/ServerEndpoint.o gs/ServerEndpoint.cpp
Debug/gs:
	mkdir Debug/gs

server: mod_server mod_log Debug/Account.o 
#	g++ -o server Debug/Server.o Debug/log/log.o
mod_server: Debug/Server.o

Debug/Server.o: 
	g++ -c -o Debug/Server.o Server.cpp
Debug/Account.o: mod_log gs/Account.h
	g++ -c -o Debug/Account.o gs/Account.cpp -I D:\\usr\\srv\\mysql51\\include 

mod_log: Debug/log/log.o

Debug/log/log.o: Debug/log log/log.h dllexport.h
	g++ -c -o Debug/log/log.o log/log.cpp
Debug/log: 
	mkdir Debug/log

test: AccountTest

AccountTest: Debug/AccountTest.o Debug/Account.o Debug/log/log.o
#	g++ -o Debug/AccountTest Debug/AccountTest.o Debug/Account.o Debug/log/log.o -lmysqlclient -Wl,-Bdynamic -lgcc_s
	g++ -o Debug/AccountTest Debug/AccountTest.o Debug/Account.o Debug/log/log.o -lmysqlclient
Debug/AccountTest.o: 
	g++ -c -o Debug/AccountTest.o test/AccountTest.cpp