
#include "Proxyserver.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace ::apache::thrift;
using namespace std;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using namespace Test;


int main(int argc, char **argv) {

  boost::shared_ptr<TSocket> socket(new TSocket(argv[1], 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  Response webpage;
  ProxyserverClient client(protocol);
  transport->open();
  string line;
  ifstream urls("url_list.txt");
  while (getline(urls, line)){
    client.request(webpage,line);
//    cout<<endl<<webpage.doc;
    cout<<endl<<line<<"   "<<webpage.response_code;
  }
  transport->close();
  return 0;
}

