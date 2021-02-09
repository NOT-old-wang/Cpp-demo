cmake_minimum_required(VERSION 3.5.1)
project(eigen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
  include
  /usr/local/include
  /usr/local/opt/eigen/include/eigen3
  /usr/include/eigen3
)
# set(CMAKE_BUILD_TYPE "Release")
# set(CMAKE_CXX_FLAGS "-O2")

# add_executable(${PROJECT_NAME}_demo1 demo_1.cc )
# add_executable(${PROJECT_NAME}_demo2 demo_2.cc )
# add_executable(${PROJECT_NAME}_demo3 demo_3.cc )
# add_executable(${PROJECT_NAME}_robot_test robot_test.cc)
add_executable(${PROJECT_NAME}_rigid_body_motion rigid_body_motion.cc)