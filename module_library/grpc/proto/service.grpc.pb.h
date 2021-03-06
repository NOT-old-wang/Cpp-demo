// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/service.proto
// Original file comments:
// 语法版本
#ifndef GRPC_proto_2fservice_2eproto__INCLUDED
#define GRPC_proto_2fservice_2eproto__INCLUDED

#include "proto/service.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc_demo {
namespace service {

// 服务: 可用于 RPC
// service 定义开放调用的服务，即 UserInfoService 微服务
class UserInfoService final {
 public:
  static constexpr char const* service_full_name() {
    return "grpc_demo.service.UserInfoService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // rpc 定义服务内的 GetUserInfo 远程调用
    virtual ::grpc::Status GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc_demo::service::UserResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpc_demo::service::UserResponse>> AsyncGetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpc_demo::service::UserResponse>>(AsyncGetUserInfoRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpc_demo::service::UserResponse>> PrepareAsyncGetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpc_demo::service::UserResponse>>(PrepareAsyncGetUserInfoRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // rpc 定义服务内的 GetUserInfo 远程调用
      virtual void GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpc_demo::service::UserResponse>* AsyncGetUserInfoRaw(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpc_demo::service::UserResponse>* PrepareAsyncGetUserInfoRaw(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc_demo::service::UserResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>> AsyncGetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>>(AsyncGetUserInfoRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>> PrepareAsyncGetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>>(PrepareAsyncGetUserInfoRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, std::function<void(::grpc::Status)>) override;
      void GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void GetUserInfo(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void GetUserInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_demo::service::UserResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>* AsyncGetUserInfoRaw(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::grpc_demo::service::UserResponse>* PrepareAsyncGetUserInfoRaw(::grpc::ClientContext* context, const ::grpc_demo::service::UserRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetUserInfo_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // rpc 定义服务内的 GetUserInfo 远程调用
    virtual ::grpc::Status GetUserInfo(::grpc::ServerContext* context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetUserInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetUserInfo() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetUserInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetUserInfo(::grpc::ServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetUserInfo(::grpc::ServerContext* context, ::grpc_demo::service::UserRequest* request, ::grpc::ServerAsyncResponseWriter< ::grpc_demo::service::UserResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetUserInfo<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_GetUserInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_GetUserInfo() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc_demo::service::UserRequest, ::grpc_demo::service::UserResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc_demo::service::UserRequest* request, ::grpc_demo::service::UserResponse* response) { return this->GetUserInfo(context, request, response); }));}
    void SetMessageAllocatorFor_GetUserInfo(
        ::grpc::experimental::MessageAllocator< ::grpc_demo::service::UserRequest, ::grpc_demo::service::UserResponse>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::grpc_demo::service::UserRequest, ::grpc_demo::service::UserResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_GetUserInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetUserInfo(::grpc::ServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* GetUserInfo(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* GetUserInfo(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_GetUserInfo<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_GetUserInfo<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetUserInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetUserInfo() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetUserInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetUserInfo(::grpc::ServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetUserInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetUserInfo() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetUserInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetUserInfo(::grpc::ServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetUserInfo(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_GetUserInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_GetUserInfo() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetUserInfo(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_GetUserInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetUserInfo(::grpc::ServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* GetUserInfo(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* GetUserInfo(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetUserInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetUserInfo() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::grpc_demo::service::UserRequest, ::grpc_demo::service::UserResponse>(std::bind(&WithStreamedUnaryMethod_GetUserInfo<BaseClass>::StreamedGetUserInfo, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_GetUserInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetUserInfo(::grpc::ServerContext* /*context*/, const ::grpc_demo::service::UserRequest* /*request*/, ::grpc_demo::service::UserResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetUserInfo(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::grpc_demo::service::UserRequest,::grpc_demo::service::UserResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GetUserInfo<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_GetUserInfo<Service > StreamedService;
};

}  // namespace service
}  // namespace grpc_demo


#endif  // GRPC_proto_2fservice_2eproto__INCLUDED
