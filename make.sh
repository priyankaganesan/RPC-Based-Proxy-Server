#!/bin/bash
g++ -Wall -I/usr/local/include/thrift -c Proxyserver.cpp -o proxyserver.o
g++ -Wall -I/usr/local/include/thrift -c Proxyserver_server.cpp -o server.o
g++ -Wall -I/usr/local/include/thrift -c proxyserver_constants.cpp -o constants.o
g++ -Wall -I/usr/local/include/thrift -c proxyserver_types.cpp -o types.o
g++ -Wall -I/usr/local/include/thrift -c Something_client.cpp -o client.o
g++ -L/usr/local/lib server.o something.o constants.o types.o -o Proxyserver_server -lthrift
g++ -L/usr/local/lib client.o something.o constants.o types.o -o Proxyserver_client -lthrift
