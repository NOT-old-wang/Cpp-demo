cmake_minimum_required(VERSION 3.5.1)
project(gflag)

find_package(gflags REQUIRED)

add_executable(${PROJECT_NAME}_demo demo.cc demo_gflags.cc)
target_link_libraries(${PROJECT_NAME}_demo ${GFLAGS_LIBRARIES})

