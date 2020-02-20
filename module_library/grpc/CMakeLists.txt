cmake_minimum_required(VERSION 3.5.1)
project(grpc)

add_compile_options(-std=c++11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

set(PROTO_FILES 
  proto/service.proto
)

include(FindProtobuf)
find_package(protobuf REQUIRED)
if(PROTOBUF_FOUND)
  message(STATUS "protobuf library found")
  include_directories(${PROTOBUF_INCLUDE_DIRS})
  protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES} )
  # message("PROTO_SRCS = ${PROTO_SRCS}")
  # message("PROTO_HDRS = ${PROTO_HDRS}")
else(PROTOBUF_FOUND)
  message(FATAL_ERROR "protobuf library is needed but can't be found")
endif(PROTOBUF_FOUND)

find_package(GRPC REQUIRED)
if(GRPC_FOUND)
  message(STATUS "grpc library found")
  set(GRPC_GRPCPP_REFLECTION gRPC::grpc++_reflection)
  include_directories(${GRPC_INCLUDE_DIR})
  grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${CMAKE_CURRENT_BINARY_DIR} ${PROTO_FILES})
else(GRPC_FOUND)
  message(FATAL_ERROR "grpc library is needed but can't be found")
endif(GRPC_FOUND)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME}_client 
  client.cc   
  ${PROTO_SRCS} 
  ${PROTO_HDRS}
  ${GRPC_SRCS}
  ${GRPC_HDRS}
)

add_executable(${PROJECT_NAME}_server 
  server.cc   
  ${PROTO_SRCS} 
  ${PROTO_HDRS}
  ${GRPC_SRCS}
  ${GRPC_HDRS}
)


target_link_libraries(${PROJECT_NAME}_server
  ${PROTOBUF_LIBRARIES}
  ${GRPC_LIBRARY}
  ${GRPC_GRPCPP_REFLECTION}
)

target_link_libraries(${PROJECT_NAME}_client
  ${PROTOBUF_LIBRARIES}
  ${GRPC_LIBRARY}
  ${GRPC_GRPCPP_REFLECTION}
)