# cpp 中的一些知识

## 变量相关
### const
[修改const](https://blog.csdn.net/zz460833359/article/details/48917217?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.control)

#### 总结
1. const常量只是一个编译期间的常量，存放在堆栈区的const变量可通过指针隐式的修改
2. const全局变量存储在全局/静态存储区的只读区，修改会引发段错误
3. c++中的常量折叠：指const变量（即常量）值放在编译器的符号表中，计算时编译器直接从表中取值，省去了访问内存的时间，从而达到了优化。

### static
注意点：始终驻留在全局数据区,直到程序运行结束。但其作用域为局部作用域,当定义它的函数或语句块结束时，其作用域随之结束

#### 使用场景
```
修饰对象/变量
修饰方法/函数  --> 静态函数不能被其它文件所用，其它文件中可以定义相同名字的函数，不会发生冲突
```