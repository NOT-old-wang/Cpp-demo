cmake_minimum_required(VERSION 3.5.1)
project(perftools)

add_compile_options(-std=c++11)

add_executable(${PROJECT_NAME}_test
  test.cc 
)

target_link_libraries (${PROJECT_NAME}_test
  "profiler"
)