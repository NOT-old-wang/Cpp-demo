# gflag
## 概要
- gflags是Google的一个开源项目，用于解析程序运行参数。gflags简单易用，它的好处在于统一配置格式，减少开发工作量。

## 编译
```bash
$ cd gflag
$ mkdir build
$ cmake ..
$ make
```

## 执行
```bash
# 不加命令行
$ ./gflag_demo
# 加命令行变量控制 `-test_bool=true` test_bool为程序开头定义的标志
$ ./gflag_demo -test_bool=true -test_int32=666
# 加命令行文件输入 `-flagfile=filename` 注意路径, - 和 -- 一样
$ ./gflag_demo -flagfile=/home/wangjy/Programming/module_library/gflag/demo.gflags
# 其他
# -fromenv=value 从环境中读取value
# --tryfromenv=value 环境中是否未定义不是致命错误
```
- [gflag规范](https://blog.csdn.net/zhanggongwu/article/details/82084713)

## 参考教程
- [官方文档](https://gflags.github.io/gflags/)
- [简书参考](https://www.jianshu.com/p/2179938a818d)
- [blog参考](http://www.yeolar.com/note/2014/12/14/gflags/)