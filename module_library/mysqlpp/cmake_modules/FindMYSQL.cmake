# - Find mysqlclient
# Find the native MySQL includes and library
#
#  MYSQL_INCLUDE_DIR - where to find mysql.h, etc.
#  MYSQL_LIBRARIES   - List of libraries when using MySQL.
#  MYSQL_FOUND       - True if MySQL found.

if(MYSQL_INCLUDE_DIR)
  # Already in cache, be silent
  set(MYSQL_FIND_QUIETLY true)
endif (MYSQL_INCLUDE_DIR)

# 从下面那两个路径找mysql.h，将找到的路径放到MYSQL_INCLUDE_DIR这个变量中。
find_path(MYSQL_INCLUDE_DIR mysql.h
  /usr/local/include/mysql
  /usr/include/mysql
)

# 设置要寻找的链接库的名字，这里应该是找libmysqlclient.so
set(MYSQL_NAMES mysqlclient mysqlclient_r)
# 将libmysqlclient.so的路径放到MYSQL_LIBRARY
find_library(MYSQL_LIBRARY
  names ${MYSQL_NAMES}
  paths /usr/lib /usr/local/lib
  PATH_SUFFIXES mysql
)

# 如果上面找到mysql的头文件和mysql的库文件，就将MYSQL_FOUND设为真
if(MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)
  set(MYSQL_FOUND true)
  set(MYSQL_LIBRARIES ${MYSQL_LIBRARY} )
else(MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)
  set(MYSQL_FOUND FALSE)
  set(MYSQL_LIBRARIES )
endif(MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)

# 如果找到并且没有设置QUIET，则输出搜到动态库路径
# 如果找不到就输出错误信息
if(MYSQL_FOUND)
  if (NOT MYSQL_FIND_QUIETLY)
    message(STATUS "Found MySQL: ${MYSQL_LIBRARY}")
  endif(NOT MYSQL_FIND_QUIETLY)
else(MYSQL_FOUND)
  if(MYSQL_FIND_REQUIRED)
    message(STATUS "Looked for MySQL libraries named ${MYSQL_NAMES}.")
    message(FATAL_ERROR "Could NOT find MySQL library")
  endif(MYSQL_FIND_REQUIRED)
endif(MYSQL_FOUND)

# 将他标记为高级变量
mark_as_advanced(
  MYSQL_LIBRARY
  MYSQL_INCLUDE_DIR
)