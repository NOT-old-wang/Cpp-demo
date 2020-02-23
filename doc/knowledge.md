# 相关知识和术语

- DDS
```
数据分发服务: data dustribution service: 一种国际标准，采用发布/订阅体系架构, 以数据为中心, 提供丰富的Qos服务质量策略
1: DLRL层（数据本地重构）
2: DCPS层（以数据为中心发布订阅）
```
[参考](https://blog.csdn.net/bossxu_linuxer/article/details/81216030)
> 注: DDS中以数据为中心的发布/订阅(DCPS)模型构建了一个共享的`全局数据空间`的概念，所有的数据对象都存在于此空间中，分布式节点通过简单的读、写操作便可以访问这些数据对象。实际上，数据并非存在于所有计算机的地址空间中，它仅存在于那些对它感兴趣的应用程序的本地缓存中，而这一点正是发布/订阅模型的关键所在。 

- RTPS
```
Real Time Publish Subscribe: DDS标准中的一个子集, DDS标准中的通讯协议部分
```

- fastRTPS
```
Fast RTPS 是 eProsima 公司对RTPS标准的一个实现的一个库
```

- Qos
```
Quility of Service: 指一个网络能够利用各种基础技术，为指定的网络通信提供更好的服务能力, 是网络的一种安全机制, 是用来解决网络延迟和阻塞等问题的一种技术
```

- IDL
```
interface description language: 过一种中立的方式来描述接口，使得在不同平台上运行的对象和用不同语言编写的程序可以相互通信交流
```

- RAII
```
Resource Acquisition Is Initialization: 资源获取就是初始化”，是c++等编程语言常用的管理资源、避免内存泄露的方法。它保证在任何情况下，使用对象时先构造对象，最后析构对象
```