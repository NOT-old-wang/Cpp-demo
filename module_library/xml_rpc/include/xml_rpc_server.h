#ifndef XML_RPC_SERVER_H_
#define XML_RPC_SERVER_H_

#include "xmlrpc-c/base.hpp"
#include "xmlrpc-c/registry.hpp"
#include "xmlrpc-c/server_abyss.hpp"

#include <sys/signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <cstring>
#include <iostream>

class XmlRpcServer {
 private:
  class MyTestMethod : public xmlrpc_c::method {
   public:
    MyTestMethod() {
      this->_signature = "A:ii";
      this->_help = "This method adds two integers together";
    }

    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value* const retval) {
      const int addend(paramList.getInt(0));
      const int adder(paramList.getInt(1));

      *retval = (xmlrpc_c::value_int)(addend + adder);
    }
  };

 private:
  xmlrpc_c::registry addIntRegistry;
  xmlrpc_c::serverAbyss* AbyssServer;
  int port;
  int socket_fd;

 public:
  void RegesterXmlMethod() {
    xmlrpc_c::methodPtr add_int(new XmlRpcServer::MyTestMethod);
    addIntRegistry.addMethod("add.int", add_int);
  }

  int SetupServer() {
    AbyssServer = new xmlrpc_c::serverAbyss(xmlrpc_c::serverAbyss::constrOpt()
                                                .registryP(&addIntRegistry)
                                                .socketFd(socket_fd));
    std::cout << "Xmlrpc server is running......" << std::endl;
    AbyssServer->run();
    std::cout << "Xmlrpc server stopped" << std::endl;
    return 0;
  }

  int SetupSocket() {
    int rc;
    int yes = 1;
    struct sockaddr_in rm_add;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == socket_fd) {
      std::cout << "Can not open server socket: " << std::endl;
      return -1;
    }

    rc = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    if (-1 == rc) {
      std::cout << "Can not set socket options: " << std::endl;
      return -1;
    }

    rm_add.sin_family = AF_INET;
    rm_add.sin_port = htons(port);
    rm_add.sin_addr.s_addr = INADDR_ANY;

    rc = bind(socket_fd, (struct sockaddr*)&rm_add, sizeof(struct sockaddr));
    if (-1 == rc) {
      std::cout << "Can not bind to port " << port << std::endl;
      close(socket_fd);
      return -1;
    }

    return 0;
  }

 public:
  XmlRpcServer(int _port) : port(_port), socket_fd(-1) {}
};

#endif  // XML_RPC_SERVER_H_
