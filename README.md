# RPC-Based-Proxy-Server

//Yo!!! Pls Don't use python style comments
//Sorry my bad!!!

//This is a file that provides the commands necessary to run client and server programs.

//First create a my_thrift_file.thrift
//Refer http://wiki.apache.org/thrift/ThriftUsageC%2B%2B

//Then copy server skeleton to .cpp file
//Create client.cpp file


//Compiling Server
g++ -Wall -I/usr/local/include/thrift -c Something.cpp -o something.o
g++ -Wall -I/usr/local/include/thrift -c Something_server.cpp -o server.o
g++ -Wall -I/usr/local/include/thrift -c my_thrift_file_constants.cpp -o constants.o
g++ -Wall -I/usr/local/include/thrift -c my_thrift_file_types.cpp -o types.o


//Compiling Client
g++ -Wall -I/usr/local/include/thrift -c Something_client.cpp -o client.o

//Linking Server
g++ -L/usr/local/lib server.o something.o constants.o types.o -o Something_server -lthrift

//Linking Client
g++ -L/usr/local/lib client.o something.o constants.o types.o -o Something_client -lthrift

//For running pls use common sense!! :D
