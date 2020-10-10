# gperftools
## 概要
- `gperftools`是`google`开发的一款非常实用的工具集，
- 主要包括：
1. `tcmalloc`: 高性能内存管理库
2. `heap-profiler`,`heap-checker`: 基于 tcmalloc 的堆内存检测和内存泄漏分析工具
3. `cpu-profiler`: 基于 tcmalloc 实现的程序CPU性能监测工具

## 安装gperftools
### 依赖安装:
- libunwind库： 基于64位CPU和操作系统的程序提供了基本的堆栈辗转开解功能，其中包括用于输出堆栈跟踪的API、用于以编程方式辗转开解堆栈的API以及支持C++异常处理机制的API
```bash
$ sudo apt-get install libunwind-dev
```
### 源码安装:
```bash
$ git clone https://github.com/gperftools/gperftools.git
$ ./autogen.sh
# 可以使用prefix命令指定安装目录， 如 --prefix=/home/tools/gpreflstools
$ ./configure  
$ make
$ sudo make install
```

## 使用 cpu profiler
- 用于分析程序性能，找到程序的性能瓶颈； 通过采样，对cpu进行'画像'，对函数关系和函数耗时进行统计 -> 方便程序员去优化，先优化最耗时的
```bash
# 方法1: 直接链接，只要加上-lprofiler对程序重新编译一次, 设置环境变量 CPUPROFILER 指定生成的性能报告文件，并执行自己的程序
$ # TODO export CPUPROFILE=test.prof.out
# 方法2: 通过api,添加头文件,用ProfilerStart()和ProfilerStop()
$ g++ -std=c++11 cpu_profile_demo.cc -o demo -ltcmalloc -lprofiler
$ ./demo
# 然后执行程序，退出程序以后，你会发现当前目录生成了一个文件 demo.prof,
```

## 使用 heap-profiler


## 相关工具
- pprof工具: 用脚本将结果显示的更加直观, pprof --help
```bash
$ pprof ./demo demo.prof --text # 输出报告信息到终端
$ pprof ./demo demo.prof --text > test.txt # 输入到文本
$ pprof ./demo demo.prof --pdf > test.pdf # 输入到pdf
$ pprof ./demo demo.prof --gv --focus=vsnprintf  # 只关注某个函数
$ pprof ./demo demo.prof --gv --ignore=snprintf  # 过滤掉某个函数
```


## 参考教程
- [官方文档](https://gperftools.github.io/gperftools/)
- [blog参考](https://blog.csdn.net/zsl_oo7/article/details/72625520)

## 问题
- [动态库无法链接,找不到](https://blog.csdn.net/hankerbit/article/details/83834349)
