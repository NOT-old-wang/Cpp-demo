# protobuf
## 概要
- protocol buffers 是Google开源的一种灵活,高效,自动化机制的结构数据序列化方法; 可类比 XML, json

## 编译
```bash
$ cd protobuf
$ mkdir build
$ cmake ..
$ make
```

## 执行
```bash
$ ./protobuf_demo
```

# 生成 cpp 文件
```
可以在 proto 目录下手动执行 protoc demo.proto --cpp_out=. 来产生。
```
## 参考教程
- [官方文档](https://developers.google.com/protocol-buffers/docs/overview)
- [简介](https://www.jianshu.com/p/e06ba6249edc)
- [中文翻译文档](https://www.jianshu.com/p/b33ca81b19b5)
- [CMake链接protobuf](https://cmake.org/cmake/help/v3.1/module/FindProtobuf.html)

## 其他资料
- [性能比较](https://zhuanlan.zhihu.com/p/53339153)