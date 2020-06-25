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
- [mysqlpp官方文档](https://tangentsoft.com/mysqlpp/doc/html/userman/)
- [简单使用](https://blog.csdn.net/letterwuyu/article/details/77940164)
- [mysql](https://www.w3school.com.cn/sql/index.asp) 
- [参考](https://github.com/chengxh110/mysqlpp_demo)

### MySQL 基本语法：  
- 打开 MySQL 服务  
sudo service mysql start   
- 使用 root 用户登录，+密码  
mysql -u root -p +password  

#### 在 MySQL 控制台中输入命令，搭建数据库：  
- 进入sql服务后首先查看有哪些数据库  
show databases;  
- 若没有新建一个  
CREATE DATABASE demo_test;  
- 使用数据库  
use demo_test;  

#### 新建表并使用查看  
- 查看有哪些表  
show tables;  
- 新建表：CREATE TABLE xxxx();  
--书：书名和作者  
CREATE TABLE book(name char(20),author char(20));  
--读者：人名、借书日期以及性别  
CREATE TABLE reader(name char(20),date int(10),sex char(5));  

- 查看表的内容：SELECT * FROM xxx;  
SELECT * FROM book;  
SELECT * FROM reader;  
  
- 插入内容到表：INSERT INTO xxx VALUES();  
INSERT INTO 表名称 VALUES (值1, 值2,....);  
INSERT INTO table_name (列1, 列2,...) VALUES (值1, 值2,....);  
>eg:  
INSERT INTO book VALUES('c language','niuren')  
INSERT INTO book VALUES('java','lihairen')，('python','yjj')  
 
- INSERT INTO reader VALUES('kumata',20180530,'man');  
INSERT INTO reader(name,sex) VALUES('kusada','man');  
INSERT INTO reader(name,date) VALUES('wuyifan',20187475);  
 
- 再查看 即可显示已添数据  
SELECT * FROM book;  
SELECT * FROM reader;  

- 高级(一些函数语句)
ORDER BY rating DESC （排序 降序）
MOD(3, 2) (对2取模)
<>  (!=)
TODO(others)

#### 查询数据表  
- SQL SELECT 语句  
SELECT 列名称 FROM 表名称  
SELECT * FROM 表名称  
>eg:  
如需获取名为 "LastName" 和 "FirstName" 的列的内容（从名为 "Persons" 的数据库表）:  
SELECT LastName,FirstName FROM Persons;  
从 "Persons" 表中选取所有的列:  
SELECT * FROM Persons;  

- WHERE 子句  
有条件地从表中选取数据，可将 WHERE 子句添加到 SELECT 语句:  
SELECT 列名称 FROM 表名称 WHERE 列 运算符 值  

>eg:  
只希望选取居住在城市 "Beijing" 中的人...:  
SELECT * FROM Persons WHERE City='Beijing';  
SELECT * FROM Persons WHERE FirstName='Bush';  
SELECT * FROM Persons WHERE Year>1965;  

- AND 和 OR 运算符  
在 WHERE 子语句中把两个或多个条件结合起来  
SELECT * FROM Persons WHERE FirstName='Thomas' AND LastName='Carter';  
SELECT * FROM Persons WHERE firstname='Thomas' OR lastname='Carter';  
SELECT * FROM Persons WHERE (FirstName='Thomas' OR FirstName='William') AND LastName='Carter'  

### 修改表中数据  
- Update 语句  
UPDATE   SET 列名称 = 新值 WHERE 列名称 = 某值  
>eg:更新某一行中的一个列:  
UPDATE Person SET FirstName = 'Fred' WHERE LastName = 'Wilson';  
>eg:更新某一行中的若干列:  
UPDATE Person SET Address = 'Zhongshan 23', City = 'Nanjing' WHERE LastName = 'Wilson';  

#### 删除数据  
- 删除数据表：  
DROP TABLE xxx(table_name);  

- DELETE 语句：删除表中的行:  
DELETE FROM 表名称 WHERE 列名称 = 值;  
>eg:   
DELETE FROM Person WHERE LastName = 'Wilson'   
  
- 删除所有数据行，保留表的结构、属性和索引:  
DELETE FROM table_name;  
DELETE * FROM table_name;  

#### 导出、导入数据库文件  
- 导出表存储为sql文件规则  
mysqldump -u userName -p 源数据库 > 目标目录中的.sql文件;  

- 导入sql文件命令规则  
mysql -u userName -p 目标数据库 < 源sql文件路径;  
----  
### mysql++  
- 核心功能点
1、通过Mysql++类库，连接Mysql  
2、实现对Mysql的增、删、改、查操作  
- 连接数据库  
通过TCP连接数据库、通过WINDOWS命名管道连接数据库、UNIX域SOCKET连接数据库  
mysqlpp::Connection  （常用）
TCPConnection  
UnixDomainSocketConnection  
WindowsNamedPipeConnection  
- 增删改查  
1、直接使用Query stream输入SQL语句  
2、使用Template Query采用类似于printf的方式进行输入SQL语句  
3、用SSQLS，通过类似于Hibernate的方式对Data Struct进行操作来操作底层数据库  
- 遍历数据  
1、所有数据结果行都拿出来到内存(store)  
2、游标一样逐行操作(use)  
3、类似于Hibernate的利用DataStruct进行直接操作的方式  
- 类
##### mysqlpp::Connection
>主要的方法就是“连接”，“断开连接”，“创建某个数据库"，”drop某个数据库“（此二者是通过CREATE  DATABASE和DROP  DATABASE实现的），”查看某张 table 中的数据行数“，”关闭mysql服务等操作  
>该类型也可以返回一个mysqlpp::Query类型，该类型主要负责查询操作。另外，当我们以后看到mysqlpp::Query的时候，我们很容易发现它的构造函数必定需要一个mysqlpp::Connection，也就是说mysqlpp::Query的所有操作，其实也就是再次调用mysqlpp::Connection的对应方法，后者再去调用mysqlpp::DBDriver来做真正的数据库操作
##### mysqlpp:: Query  
> 进行SQL语句的增删改查  
##### mysqlpp::StoreQueryResult  
> 所有数据结果行
##### mysqlpp::UseQueryResult  
> 游标一样逐行操作  
##### mysqlpp::ConnectionPool  
> 连接池  
##### mysqlpp::OpeitonalExceptions  
> 对于一个表示“是否需要抛出异常”的变量的包装

- 核心接口
MySql++支持三种查询： Query::execute(), Query::store(), Query::use()
1、execute( )接口  
用于不返回数据的查询，该函数返回一个SimpleResult对象。  
2、exec( )接口  
它返回一个bool值，标示执行成功与否；如果只要成功与否的标识，可以使用该接口。  
3、store() 接口  
用于用服务器获取数据，该函数返回一个StoreQueryResult对象。对象包含了整个查询结果，使用stl::map方式从里面取数据即可。  
4、use()接口  
同样用于从服务器获取数据，不过该函数返回UseQueryResult对象。相比store()而言更节省内存，该对象类似StoreQueryResult,但是不提供随机访问的特性。use查询会让服务器一次返回结果集的一行。
5、错误码 
Query对象的errnum()返回上次执行对应的错误代码，error()返回错误信息，affected_rows()返回受影响的行数。



