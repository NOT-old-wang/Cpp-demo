## CMakeLists 语法

### 注
```
注释：#
变量使用${}方式取值，但是在 IF 控制语句中是直接使用变量名
指令是大小写无关的，参数和变量是大小写相关的。但，推荐你全部使用大写指令
指令(参数 1 参数 2...) 参数使用括弧括起，参数之间使用空格或分号分开。
help: cmake--help [按tab]
构建失败 查看细节 make VERBOSE=1
```
### 变量：
```cmake
# 设置cmake变量SRC_LISTS 
set(SRC_LISTS
    src/mian.cpp
)
# 设置环境变量HOME
set(ENV{HOME} xxx)

# 引用cmke变量
${SRC_LISTS}
# 调用环境变量 HOME
$ENV{HOME}

# 常用变量
[变量参考](https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/Useful-Variables)
PROJECT_NAME:
PROJECT_SOURCE_DIR:
PROJECT_BINARY_DIR: 
CMAKE_CURRENT_SOURCE_DIR: CMakeLists.txt文件所在的路径
CMAKE_MODULE_PATH： 定义自己cmake模块的路径
LIBRARY_OUTPUT_PATH:  库文件存放路径
EXECUTABLE_OUTPUT_PATH: 可执行文件存放路径
CMAKE_INSTALL_PREFIX: cmake安装目录前缀， 默认为/usr/local
例： cmake -D CMAKE_INSTALL_PREFIX="/some/where/local"  ..
CMAKE_BUILD_TYPE: "Release"
CMAKE_CXX_FLAGS_RELEASE: "-O2"
例：
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# 内部隐示变量
CMAKE_C_COMPILER：指定C编译器
CMAKE_CXX_COMPILER：指定C++编译器
CMAKE_C_FLAGS：编译C文件时的选项，如-g；也可以通过add_definitions添加编译选项
CMAKE_CXX_FLAGS
EXECUTABLE_OUTPUT_PATH：可执行文件的存放路径
LIBRARY_OUTPUT_PATH：库文件路径
PROJECT_NAME  
PROJECT_BINARY_DIR  =  CMAKE_BINARY_DIR 
PROHECT_SOURCE_DIR  =  CMAKE_SOURCE_DIR
CMAKE_BUILD_TYPE：build 类型(Debug, Release, ...)，CMAKE_BUILD_TYPE=Debug
BUILD_SHARED_LIBS：Switch between shared and static libraries

调用环境变量
$ENV{NAME}
设置 set{ENV{NAME} name}
```

### 条件语句：
```cmake
if(WIN32)
    message(STATUS “This is windows.”)
#做一些 Windows 相关的操作
else(WIN32)
    message(STATUS “This is not windows”)
#做一些非 Windows 相关的操作
endif(WIN32)
```
### 循环语句：
```cmake
# examle 1
set(LIST a b c)
forearch(value ${LIST})
    # do something
    ...
endforearch(value)

# example 2
while()
    # do something
    ...
endwhile()
```
### 常用指令

#### 设定依赖的cmake版本
```cmake
cmake_minimum_required(VERSION 2.8.3)
```

#### 指定项目名称
```cmake
project(HELLO)   
```

#### 指定头文件的搜索路径，相当于指定gcc的-I参数
```cmake
include_directories (${HELLO_SOURCE_DIR}/include)
```
#### 添加编译参数

```cmake
add_definitions(-DDEBUG) # 将在gc命令行添加DEBUG宏定义
add_definitions( “-Wall -ansi –pedantic –g”)
add_definitions(-std=c++11) # set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )
```

#### 获得一个目录下的所有源文件
```cmake
# 这个指令临时被用来自动构建源文件列表
aux_source_directoies (src/ DIR_SRCS)
```
#### 包含子目录
```cmake
add_subdirectory (Hello)

# 多个文件
subdirs(dir1 dir2...)
```
#### 库文件和可执行文件相关

- 编译成可执行程序，指定编译，好像也可以添加.o文件

```cmake
add_executable (helloDemo demo.cxx demo_b.cxx)   # 将cxx编译成可执行文件
```
- 添加链接库,相同于指定-l参数

```cmake
target_link_libraries(demo Hello) # 将可执行文件与Hello连接成最终文件

link_libraries( lib1 lib2 ...)
```
- 编译成库

```cmake
# 默认生成静态库, 如果 SET(BUILD_SHARED_LIBS ON)后，默认生成的为动态库
# 静态库 .a
add_library(Hello STATIC hello.cxx)  # 将hello.cxx编译成静态库如libHello.a
# 共享库 .so
add_library(Hello SHARED hello.cxx)  # 将hello.cxx编译成共享库如libHello.so
# 设置版本 VERSION 指代动态库版本，SOVERSION 指代 API 版本
set_target_properties(hello PROPERTIES VERSION 1.2 SOVERSION 1)
# 设置库名
set_target_properties(Hello PROPERTIES OUTPUT_NAME "my_hello")
```
- 动态链接库或静态链接库的搜索路径，相当于gcc的-L参数

```cmake
link_directories (${HELLO_BINARY_DIR}/Hello)  # 增加Hello为link目录
```

#### 模块相关
- 使用模块
```cmake
# 对于系统预定义的 Find<name>.cmake 模块，使用方法一般如下：
# 每一个模块都会定义以下几个变量
# <name>_FOUND 判断模块是否被找到
# <name>_INCLUDE_DIR or <name>_INCLUDES 
# <name>_LIBRARY or <name>_LIBRARIES
find_package(CURL)
if(CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIR})
	target_link_libraries(curltest ${CURL_LIBRARY})
else(CURL_FOUND)
	message(FATAL_ERROR ”CURL library not found”)
endif(CURL_FOUND)

# 注
## find_package(<package> [version] [EXACT] [QUIET] [MODULE]
#              [REQUIRED] [[COMPONENTS] [components...]] 
#              [OPTIONAL_COMPONENTS components...]
#              [NO_POLICY_SCOPE])
# QUIET: 不输出信息
# REQUIRED： 该模块是必须的，找不到就错误
```
- 制作模块
```cmake
# 顶层CMakeListsz.txt 中添加 模块路径
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
```
```cmake
# hello.cmake 模块例程参考
# 设置头文件路径
find_path(HELLO_INCLUDE_DIR hello.h /usr/include/hello
/usr/local/include/hello)
# 设置链接库路径
find_library(HELLO_LIBRARY NAMES hello PATH /usr/lib
/usr/local/lib)
# 如果设置到位
if (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
	set(HELLO_FOUND TRUE)
endif(HELLO_INCLUDE_DIR AND HEELO_LIBRARY)

if (HELLO_FOUND)
	if (NOT HELLO_FIND_QUIETLY) ## find_package()没有设置QUIET
	message(STATUS "Found Hello: ${HELLO_LIBRARY}")
	endif (NOT HELLO_FIND_QUIETLY)
else (HELLO_FOUND)
	if (HELLO_FIND_REQUIRED)
	message(FATAL_ERROR "Could not find hello library")
	endif (HELLO_FIND_REQUIRED)
endif (HELLO_FOUND)
```

#### 打印相关
```
message([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
SATUS: 项目用户可能感兴趣的主要有趣信息。理想情况下，这些信息应该简洁，不超过一行，但仍然提供信息
WARNING: 警告，继续流程, 比较明显， 会有空断
SEND_ERROR: 产生错误，生成过程被跳过
FATAL_ERROR: 立即终止所有 cmake 过程
```

#### 安装

```
install(TARGETS <target>... [...])
install({FILES | PROGRAMS} <file>... [...])
install(DIRECTORY <dir>... [...])
install(SCRIPT <file> [...])  安装时调用 cmake脚本文件
install(CODE <code> [...])
install(EXPORT <export-name> [...])
```

```cmake
# 注意有无/ 如果目录名不以/结尾，那么这个目录将被安装为目标路径下的 abc，如果目录名以/结尾，
# 代表将这个目录中的内容安装到目标路径，但不包括这个目录本身

# 头文件目录的安装, 将程序目录下的 .h 文件安装到 /usr/local/install_directory_dir/ 下
## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION install_directory_dir/
   FILES_MATCHING PATTERN "*.h"
   # PATTERN 用于使用正则表达式进行过滤
   PATTERN ".git" EXCLUDE
   PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ
)

# 脚本文件的安装
## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
install(PROGRAMS
   scripts/my_python_script
   DESTINATION install_script_dir/
)

# 链接库的安装 将 my_lib_name 安装到相应位置[绝对路径]
## Mark executables and/or libraries for installation
install(TARGETS my_lib_name
  ARCHIVE DESTINATION ${PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${PACKAGE_BIN_DESTINATION}
)

# 文件安装
## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
   # myfile1
   # myfile2
   DESTINATION ${PACKAGE_SHARE_DESTINATION}
)
```

### 在 CMakeLists.txt 执行命令
```cmake
## exec_program(Executable [directory in which to run]
#               [ARGS <arguments to executable>]
#               [OUTPUT_VARIABLE <var>]
#               [RETURN_VALUE <var>])

exec_program(ls ARGS "*.c" OUTPUT_VARIABLE LS_OUTPUT RETURN_VALUE LS_RVALUE)
```

### 其他技巧
```cmake
# 构建失败，查看细节
make VERBOSE=1
# 将添加的头文件搜索路径放在已有路径的前面 include<hello/hello.h> -> incude<hello.h>
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE on)

# 查看可执行文件链接库情况, linux 命令
$ ldd a.out
```

###  环境变量

```bash
# 设置头文件路径 和 链接库路径
$ export CMAKE_INCLUDE_PATH=/usr/include/hello
$ export CMAKE_LIBRARY_PATH=/usr/local/lib
```
```cmake
find_path(myHeader hello.h)
if(myHeader)
include_directory(${myHeader})
endif(myHeader)
```

