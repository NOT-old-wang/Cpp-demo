cmake_minimum_required(VERSION 3.5.1)
project(protobuf)

add_compile_options(-std=c++11)

set(PROTO_FILES 
  proto/demo.proto
)

find_package(protobuf REQUIRED)
if(PROTOBUF_FOUND)
  message(STATUS "protobuf library found")
  include_directories(${PROTOBUF_INCLUDE_DIRS})
  protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
  # message("PROTO_SRCS = ${PROTO_SRCS}")
  # message("PROTO_HDRS = ${PROTO_HDRS}")
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
else(PROTOBUF_FOUND)
  message(FATAL_ERROR "protobuf library is needed but can't be found")
endif(PROTOBUF_FOUND)


add_executable(${PROJECT_NAME}_demo 
  demo.cc 
  ${PROTO_SRCS} 
  ${PROTO_HDRS}
)

target_link_libraries(${PROJECT_NAME}_demo
  ${PROTOBUF_LIBRARIES}
)