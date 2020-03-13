cmake_minimum_required(VERSION 3.5.1)
project(xml_rpc)

add_compile_options(-std=c++11)

find_package(XMLRPC REQUIRED libwww-client)
if(XMLRPC_FOUND)
  include_directories(${XMLRPC_INCLUDE_DIRS})
  message("XMLRPC_LIBRARIES = ${XMLRPC_LIBRARIES}")
  message("XMLRPC_INCLUDE_DIRS = ${XMLRPC_INCLUDE_DIRS}")
else(XMLRPC_FOUND)
  message(FATAL_ERROR "xmlrpc library is needed but can't be found")
endif(XMLRPC_FOUND)


include_directories(include)

# add_library(${PROJECT_NAME}
#   xml_rpc_server.cc
# )

add_executable(${PROJECT_NAME}_server 
  xml_rpc_server.cc
)
add_executable(${PROJECT_NAME}_client 
  xml_rpc_client.cc
)

target_link_libraries(${PROJECT_NAME}_server
  ${XMLRPC_LIBRARIES}
  # ${PROJECT_NAME}
  -lxmlrpc_server++
  -lxmlrpc++
  -lxmlrpc_server_abyss++
)
target_link_libraries(${PROJECT_NAME}_client
  ${XMLRPC_LIBRARIES}
  -lxmlrpc_client++
  -lxmlrpc++
)