cmake_minimum_required(VERSION 3.5.1)
project(eigen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
include
 /usr/local/include
)

# add_executable(${PROJECT_NAME}_demo1 demo_1.cc )
# add_executable(${PROJECT_NAME}_demo2 demo_2.cc )
# add_executable(${PROJECT_NAME}_demo3 demo_3.cc )
add_executable(${PROJECT_NAME}_robot_test robot_test.cc )

