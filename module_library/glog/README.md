# glog
## 概要
- glog 是 Google开源的日志库

## 作用
```
1: 输出等级控制: 四个等级，从小到大 INFO < WARNING < ERROR < FATAL
2: 条件控制
3: 输出日志文件
4: 检测宏
5: 崩溃处理
```

## 一些标志
- FLAGS_minloglevel = 0  // 记录的日志等级，INFO: 0, WARNING: 1, ERROR: 2 FATAL: 3
- FLAGS_log_dir = "/home/user/logs/" // 设置日志文件地址
- FLAGS_logtostderr = 1  // 使得日志信息记录到stderr而不会保存到本地日志文件中，即使你设置了FLAGS_log_dir
- FLAGS_logbufsecs = 0 // 设置可以缓冲日志的最大秒数，0指实时输出
- FLAGS_max_log_size = 10 // 设置最大日志文件大小（以MB为单位）
- FLAGS_stop_logging_if_full_disk = true // 设置是否在磁盘已满时避免日志记录到磁盘

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
```

## 参考教程
- [官方文档](...)
- [官方文档中文翻译](http://www.yeolar.com/note/2014/12/20/glog/)
- [csdn参考](https://blog.csdn.net/qq_34347375/article/details/86629421)
