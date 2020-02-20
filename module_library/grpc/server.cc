#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>
#include "service.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using grpc_demo::service::UserInfoService;
using grpc_demo::service::UserRequest;
using grpc_demo::service::UserResponse;

class UserInfoServiceImpl final : public UserInfoService::Service {
  Status GetUserInfo(ServerContext* context, const UserRequest* request,
                     UserResponse* response) override {
    response->set_name(request->name());
    response->set_id(007);
    response->set_age(25);
    response->set_sex("man");
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("127.0.0.1:0");
  UserInfoServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  std::cout << "sever start." << std::endl;

  return 0;
}