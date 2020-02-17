cmake_minimum_required(VERSION 3.5.1)
project(glog)

add_compile_options(-std=c++11)

find_package(GLOG REQUIRED)
if(GLOG_FOUND)
  message(STATUS "glog library found")
  find_path(GLOG_INCLUDE_DIR glog/logging.h)
  include_directories(${GLOG_INCLUDE_DIR})
  set(GLOG_NAMES glog)
  find_library(GLOG_LIBRARY names ${GLOG_NAMES} 
                paths /usr/lib /usr/local/lib
                PATH_SUFFIXES glog)
else(GLOG_FOUND)
  message(FATAL_ERROR "glog library is needed but can't be found")
endif(GLOG_FOUND)

add_executable(${PROJECT_NAME}_demo demo.cc)
target_link_libraries(${PROJECT_NAME}_demo ${GLOG_LIBRARY} ${GFLAGS_LIBRARIES})