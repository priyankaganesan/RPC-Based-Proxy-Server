#!/bin/bash
g++ -Wall -I/usr/local/include/thrift -c Proxyserver.cpp -o proxyserver.o
g++ -Wall -I/usr/local/include/thrift -c Proxyserver_server.cpp -o server.o
g++ -Wall -I/usr/local/include/thrift -c proxyserver_constants.cpp -o constants.o
g++ -Wall -I/usr/local/include/thrift -c proxyserver_types.cpp -o types.o
g++ -Wall -I/usr/local/include/thrift -c Proxyserver_client.cpp -o client.o
g++ -Wall -c ../Caches/LRU_cache.cpp -o LRU_cache.o
g++ -Wall -c ../Caches/fifo.cpp -o fifo.o
g++ -Wall -c ../Caches/Random.cpp -o Random.o
g++ -L/usr/local/lib server.o proxyserver.o constants.o types.o LRU_cache.o fifo.o Random.o -o Proxyserver_server -lthrift -lcurl
g++ -L/usr/local/lib client.o proxyserver.o constants.o types.o -o Proxyserver_client -lthrift -lcurl

