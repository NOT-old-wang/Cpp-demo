cmake_minimum_required(VERSION 3.15)
project(thread)

add_compile_options(-std=c++11)
 
set(USE_PROJECT stl_test/)

# find_package(Threads REQUIRED)

include_directories(${USE_PROJECT})
#add_library(${PROJECT_NAME} ${USE_PROJECT}/.cc)

add_executable(${PROJECT_NAME}_demo demo.cc)
# target_link_libraries(${PROJECT_NAME}_demo -lpthread)