#include <iostream>
#include "gflags/gflags.h"

DEFINE_bool(test_bool, false, "test bool value");
DEFINE_int32(test_int32, 666, "test int value");

DECLARE_string(server_ip);
DECLARE_int32(server_port);

int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, true);

  // for (int i = 0; i < argc; i++) {
  //   std::cout << argv[i] << std::endl;
  // }

  if (FLAGS_test_bool) {
    std::cout << "test_bool is true." << std::endl;
    std::cout << "test_int32: " << FLAGS_test_int32 << std::endl;
  }

  std::cout << "server ip: " << FLAGS_server_ip
            << " , server port: " << FLAGS_server_port << std::endl;

  return 0;
}