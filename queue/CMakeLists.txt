cmake_minimum_required(VERSION 3.15)
project(queue)

add_compile_options(-std=c++11)

set(USE_PROJECT normal/)

include_directories(${USE_PROJECT})
add_library(${PROJECT_NAME} ${USE_PROJECT}/my_queue.cc)

add_executable(${PROJECT_NAME}_demo demo.cc)
target_link_libraries(${PROJECT_NAME}_demo ${PROJECT_NAME})