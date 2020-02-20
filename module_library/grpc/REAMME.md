# grpc
## 概要
- RPC(remote procedure call 远程过程调用)框架实际是提供了一套机制，使得应用程序之间可以进行通信，而且也遵从server/client模型。使用的时候客户端调用server端提供的接口就像是调用本地的函数一样
- grpc 是 Google开源的一套远程过程调用的软件

## 安装 grpc
```bash
# 到 https://github.com/grpc/grpc 下载 tar 包, 或 clone 源码, 源码很慢
$ git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
$ cd grpc # 进入目录
$ git submodule update --init
$ make && sudo make install
```

## 需要包含的第三方库
- protobuf
- c-ares: 一个C语言的异步DNS解析库
[c-ares地址](https://c-ares.haxx.se/)
也可参考 [安装参考](https://blog.csdn.net/weixin_39986952/article/details/81168633)
- ZLIB: 提供数据压缩用的函式库
- OpenSSl: 开放式安全套接层协议, 使用这个包来进行安全通信，避免窃听，同时确认另一端连接者的身份。这个包广泛被应用在互联网的网页服务器上
- abseil

## 手动生成文件
```bash
$ protoc --cpp_out=./ proto/service.proto
$ protoc --grpc_out=./ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin proto/service.proto
```

## 编译
```bash
$ cd grpc
$ mkdir build
$ cmake ..
$ make
```

## 执行
```bash
$ ./grpc_server
$ ./grpc_client
```

## 特征
```
1. 基于HTTP/2 (连接多路复用、双向流、服务器推送、请求优先级、首部压缩等机制)
2. 交互式数据语言(IDL:Interactive Data Language) 使用 protobuf
3. 多语言支持 (C, C++, Python, PHP, Nodejs, C#, Objective-C、Golang、Java) 
```

## 应用
```
1. 低延迟、高扩展性、分布式的系统
2. 同云服务器进行通信的移动应用客户端 
3. 设计语言独立、高效、精确的新协议 
4. 便于各方面扩展的分层设计，如认证、负载均衡、日志记录、监控等
```

## 调用方式
```
1. 简单rpc, 一个请求对象对应一个返回对象 rpc simpleHello(Person) returns (Result) {}

2. 服务端流式rpc, 一个请求对象，服务端可以传回多个结果对象 rpc serverStreamHello(Person) returns (stream Result) {}

3. 客户端流式rpc, 客户端传入多个请求对象，服务端返回一个响应结果 rpc clientStreamHello(stream Person) returns (Result) {}

4. 双向流式rpc, 结合客户端流式rpc和服务端流式rpc，可以传入多个对象，返回多个响应对象 rpc biStreamHello(stream Person) returns (stream Result) {}
```

## 参考教程
- [官方文档](https://grpc.io/)
- [简介](https://segmentfault.com/a/1190000020592330)
- [中文翻译文档](http://doc.oschina.net/grpc?t=57966)
- [参考1](https://blog.csdn.net/xuduorui/article/details/78278808)
- [参考2](https://mp.weixin.qq.com/s/SxZynHR6wN7tQORNiGtY6A)
