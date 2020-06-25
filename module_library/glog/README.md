# glog
## 概要
- glog 是 Google开源的日志

## 安装 glog
```bash
$ git clone https://github.com/google/glog 
$ cd glog
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
```

## 作用
```
1: 输出等级控制: 四个等级，从小到大 INFO < WARNING < ERROR < FATAL
2: 条件控制
3: 输出日志文件
4: 检测宏
5: 崩溃处理
注：可以 gflag 配合使用
```
### 检测宏相关
```
CHECK_EQ(x,y)<<"x!=y"，EQ即equation，意为“等于”，函数判断是否x等于y，当x!=y时，函数打印出x!=y。

CHECK_NE(x,y)<<"x=y"，NE即not equation，意为“不等于”，函数判断是否x不等于y，当x=y时，函数打印出x=y。

CHECK_LE(x,y) <<"x>=y",LE即lower equation,意为小于等于，函数判断是否x小于等于y。当x>=y时，函数打印x>=y。

CHECK_LT(x,y)<<"x>=y",LT即为lower to ，意为小于，函数判断是否x小于y，当x>y时，函数打印x>y。

CHECK_GE(x,y) <<"x<=y",GE即为great equation，意为大于。判断意义根据上述可推导出。

CHECK_GT(x,y) <<"x<=y",同理如上。
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
