// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/service.proto

#include "proto/service.pb.h"
#include "proto/service.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace grpc_demo {
namespace service {

static const char* UserInfoService_method_names[] = {
  "/grpc_demo.service.UserInfoService/GetUserInfo",
};

std::unique_ptr< UserInfoService::Stub> UserInfoService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< UserInfoService::Stub> stub(new UserInfoService::Stub(channel));
  return stub;
}

UserInfoService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_GetUserInfo_(UserInfoService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status UserInfoService::Stub::GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc_demo::service::UserResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetUserInfo_, context, request, response);
}

void UserInfoService::Stub::experimental_async::GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetUserInfo_, context, request, response, std::move(f));
}

void UserInfoService::Stub::experimental_async::GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetUserInfo_, context, request, response, std::move(f));
}

void UserInfoService::Stub::experimental_async::GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetUserInfo_, context, request, response, reactor);
}

void UserInfoService::Stub::experimental_async::GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetUserInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>* UserInfoService::Stub::AsyncGetUserInfoRaw(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_demo::service::UserResponse>::Create(channel_.get(), cq, rpcmethod_GetUserInfo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>* UserInfoService::Stub::PrepareAsyncGetUserInfoRaw(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_demo::service::UserResponse>::Create(channel_.get(), cq, rpcmethod_GetUserInfo_, context, request, false);
}

UserInfoService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      UserInfoService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< UserInfoService::Service, ::grpc_demo::service::UserRequest, ::grpc_demo::service::UserResponse>(
          std::mem_fn(&UserInfoService::Service::GetUserInfo), this)));
}

UserInfoService::Service::~Service() {
}

::grpc::Status UserInfoService::Service::GetUserInfo(::grpc::ServerContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace grpc_demo
}  // namespace service

