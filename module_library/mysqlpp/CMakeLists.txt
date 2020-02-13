cmake_minimum_required(VERSION 3.5.1)
project(mysqlpp)

add_compile_options(-std=c++11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# 查找 mysql
find_package(MYSQL REQUIRED)
if(MYSQL_FOUND)
  message(STATUS "mysql library found")
  include_directories(${MYSQL_INCLUDE_DIR})
  # 我电脑中mysql++ 安装的位置
  include_directories(/usr/include/mysql++)
else()
  message(FATAL_ERROR "mysql library is needed but can't be found")
endif()

# 查找 mysqlpp
find_library(MYSQLPP_LIBRARIES mysqlpp)
message("MYSQLPP_LIBRARIES = ${MYSQLPP_LIBRARIES}")

add_executable(${PROJECT_NAME}_demo 
  demo.cc
)

target_link_libraries(${PROJECT_NAME}_demo
  ${MYSQL_LIBRARY}
  ${MYSQLPP_LIBRARIES}
)