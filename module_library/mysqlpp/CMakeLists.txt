cmake_minimum_required(VERSION 3.5.1)
project(mysqlpp)

add_compile_options(-std=c++11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# 查找 mysql
# find_package(MYSQL REQUIRED)
# if(MYSQL_FOUND)
#   message(STATUS "mysql library found")
#   include_directories(${MYSQL_INCLUDE_DIR})
# else(MYSQL_FOUND)
#   message(FATAL_ERROR "mysql library is needed but can't be found")
# endif(MYSQL_FOUND)

# 查找 mysqlpp
find_package(MYSQLPP REQUIRED)
if(MYSQLPP_FOUND)
  message(STATUS "mysqlpp library found")
  include_directories(${MYSQLPP_INCLUDE_DIR})
else(MYSQLPP_FOUND)
  message(FATAL_ERROR "mysqlpp library is needed but can't be found")
endif(MYSQLPP_FOUND)

add_executable(${PROJECT_NAME}_demo 
  demo.cc
)

target_link_libraries(${PROJECT_NAME}_demo
  ${MYSQLPP_LIBRARIES}
)