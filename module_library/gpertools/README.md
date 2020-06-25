# gflag
## 概要
- gperftools是google开发的一款非常实用的工具集，
- 主要包括：
```
1: 性能优异的 malloc, free内存分配器: tcmalloc
2: 基于 tcmalloc 的堆内存检测和内存泄漏分析工具 heap-profiler, heap-checker(检测内存泄漏)
3: 基于 tcmalloc 实现的程序CPU性能监测工具 cpu-profiler.
```
## 作用
```
定位内存泄漏,提高 malloc, free内存分配性能
服务器进程的性能分析监控,寻找性能热点
```

## 运行方式
```
1: 把tcmalloc库编译进工程 --> 官方推荐
2: 只需要在运行时通过LD_PRELOAD命令加载tcmalloc库
```

## 编译
```bash
$ cd gflag
$ mkdir build
$ cmake ..
$ make
```

## 执行
```bash
$ ./gflag_demo
# 加命令行变量控制 `-test_bool=true` test_bool为程序开头定义的标志
$ ./gflag_demo -test_bool=true -test_int32=666
```
- [gflag规范](https://blog.csdn.net/zhanggongwu/article/details/82084713)

## 参考教程
- [官方文档](https://gflags.github.io/gflags/)
- [简书参考](https://www.jianshu.com/p/2179938a818d)
- [blog参考](https://blog.csdn.net/breaksoftware/article/details/81234967?utm_source=distribute.pc_relevant.none-task)