# mysqlpp
## 概要
- mysql++是对于mysql c API的一个封装，为C++开发者提供像操作STL容器一样方便的操作数据库的一套机制

## MySql 测试
[参考](https://www.cnblogs.com/wunaozai/p/3618383.html)
```bash
$ mysql -u root -p
mysql> create database test; 
mysql> use test;    //切换到test数据库中
mysql> create table test(name varchar(255),num int(10) ); //创建一个叫test的表
mysql> show create table test;  //显示刚才创建的表信息
mysql> select * from test; 　　 //查询test表中数据
mysql> exit 
$ g++ sql.cc `mysql_config --cflags --libs` -o sql
$ ./sql
```
可以发现 test 数据库里多了一个test表，表里多了程序里插入的数据
## 编译
```bash
$ cd mysqlpp
$ mkdir build
$ cmake ..
$ make
```

## 执行
```bash
$ ./mysqlpp_demo
```

## 安装 mysql
[mac 安装](https://www.cnblogs.com/nickchen121/p/11145123.html)

## 安装 mysqlpp
```
源码安装
```
## 参考教程
- [官方文档](https://tangentsoft.com/mysqlpp/doc/html/userman/)
- [简单使用](https://blog.csdn.net/letterwuyu/article/details/77940164)
