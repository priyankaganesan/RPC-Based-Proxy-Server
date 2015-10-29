// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Proxyserver.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <string.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::Test;

class ProxyserverHandler : virtual public ProxyserverIf {
 public:
  ProxyserverHandler() {
    // Your initialization goes here
  }

  void request(Response& _return, const std::string& url) {
    // Your implementation goes here
    printf("request\n");
  }

  void shutdown() {
    // Your implementation goes here
    printf("shutdown\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ProxyserverHandler> handler(new ProxyserverHandler());
  shared_ptr<TProcessor> processor(new ProxyserverProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
