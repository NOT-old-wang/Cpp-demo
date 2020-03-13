#include "xml_rpc_server.h"

int main(int argc, char *argv[]) {
  XmlRpcServer myServer(2655);

  if (myServer.SetupSocket() != 0) {
    return -1;
  }

  myServer.RegesterXmlMethod();

  if (myServer.SetupServer() != 0) {
    std::cout << "cannot set RPC Server" << std::endl;
    return -1;
  }

  return 0;
}