#include <google/protobuf/message_lite.h>
#include <fstream>
#include <iostream>
#include "demo.pb.h"

#define USE_STREAM 1
#define USE_STRING 0

int main(int argc, const char **argv) {
  // 服务端 配置数据
  protobuf::demo::Person person_server;
  person_server.set_name("protobuf demo");
  person_server.set_id(1234);
  person_server.set_email("protobuf@demo.com");
  std::cout << person_server.DebugString() << std::endl;

  // 客户端
  protobuf::demo::Person person_client;
  std::cout << "before parse: " << person_client.DebugString() << std::endl;

  // 使用流的方式
#if USE_STREAM
  {
    std::fstream output("proto_demo", std::ios::out | std::ios::binary);
    person_server.SerializeToOstream(&output);
    output.close();

    std::fstream input("proto_demo", std::ios::in | std::ios::binary);
    person_client.ParseFromIstream(&input);
    input.close();
  }
#endif
  // 使用字符串的方式
#if USE_STRING
  {
    std::string proto_string;
    person_server.SerializeToString(&proto_string);

    person_client.ParseFromString(proto_string);
  }
#endif

  // std::cout << "client name: " << person_client.name() << std::endl;
  // std::cout << "client id: " << person_client.id() << std::endl;
  // std::cout << "client email: " << person_client.email() << std::endl;
  std::cout << "later parse: " << person_client.DebugString() << std::endl;

  // 复合类型
  {
    // 放入一个 phone
    protobuf::demo::Person::PhoneNumber *phone_number1 =
        person_server.add_phone();
    phone_number1->set_number("123");
    phone_number1->set_type(protobuf::demo::Person::WORK);

    protobuf::demo::Person::PhoneNumber *phone_number2 =
        person_server.add_phone();

    std::cout << "phone size: " << person_server.phone_size() << std::endl;

    switch (person_server.phone(0).type()) {
      case protobuf::demo::Person::WORK: {
        std::cout << "work phone." << std::endl;
        break;
      }
      case protobuf::demo::Person::MOBILE: {
        std::cout << "mobile phone." << std::endl;
        break;
      }
      case protobuf::demo::Person::HOME: {
        std::cout << "home phone." << std::endl;
        break;
      }
      default:
        break;
    }
  }
  return 0;
}