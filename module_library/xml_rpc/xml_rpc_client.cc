#include <iostream>
#include <stdlib.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/client_simple.hpp>

int main(int argc, char *argv[]) {
  int a, b, int_result;
  xmlrpc_c::value result;
  if (argc != 3) {
    std::cout << "please input Two interger numbers: " << std::endl;
    std::cin >> a >> b;
  } else {
    a = atoi(argv[1]);
    b = atoi(argv[2]);
  }

  xmlrpc_c::clientSimple myClient;
  myClient.call("http://localhost:2655/RPC2", "add.int", "ii", &result, a, b);
  int_result = (xmlrpc_c::value_int)result;
  std::cout << "sum of " << a << " and " << b << " is " << int_result
            << std::endl;

  return 0;
}
