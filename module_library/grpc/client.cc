#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>
#include "service.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using grpc_demo::service::UserInfoService;
using grpc_demo::service::UserRequest;
using grpc_demo::service::UserResponse;

class UserInfoClient {
 public:
  UserInfoClient(std::shared_ptr<Channel> channel)
      : stub_(UserInfoService::NewStub(channel)) {}

  UserResponse GetUserInfo(const std::string& user) {
    // 请求的数据
    UserRequest request;
    request.set_name(user);
    // 回复数据
    UserResponse response;

    // 处理上下文
    ClientContext context;

    Status status = stub_->GetUserInfo(&context, request, &response);

    if (status.ok()) {
      return response;
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return UserResponse();
    }
  }

 private:
  std::unique_ptr<UserInfoService::Stub> stub_;
};

int main(int argc, char** argv) {
  UserInfoClient worker(
      grpc::CreateChannel("127.0.0.1:0", grpc::InsecureChannelCredentials()));

  UserResponse response = worker.GetUserInfo("old wang");
  std::cout << "worker received." << std::endl;
  std::cout << "user name: " << response.name() << ", id: " << response.id()
            << ", age: " << response.age() << ", sex: " << response.sex()
            << std::endl;

  return 0;
}
