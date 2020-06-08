# perftools
## 概要
- 一个堆外内存分析工具.

## 安装
### 依赖：
- libunwind库： 基于64位CPU和操作系统的程序提供了基本的堆栈辗转开解功能，其中包括用于输出堆栈跟踪的API、用于以编程方式辗转开解堆栈的API以及支持C++异常处理机制的API

```bash
$ sudo apt-get install libunwind-dev
```
### 源码安装
```bash
$ git clone https://github.com/gperftools/gperftools.git
$ # 可以使用prefix命令指定安装目录， 如 --prefix=/data0/java/deploy/google-perftools/local/gperftools-2.5/
$ ./configure  
$ make
$ sudo make install
```

## 使用
```bash
$ # 链接的时候加上 /usr/local/lib/libprofiler.so
$  g++ -std=c++11 -lprofiler -L /usr/local/lib test.cc
$ # 然后执行程序，退出程序以后，你会发现当前目录生成了一个文件out.prof
$  pprof --text perftools_test out.prof 
$  pprof proc out.prof --text > test.txt # 输入到文本
```
```bash
$ pprof proc test.prof --gv --focus=vsnprintf  # 只关注某个函数
$ pprof proc test.prof --gv --ignore=snprintf  # 过滤掉某个函数
```
## 问题
[动态库无法链接,找不到](https://blog.csdn.net/hankerbit/article/details/83834349)

## 参考
[参考](https://blog.csdn.net/zsl_oo7/article/details/72625520)