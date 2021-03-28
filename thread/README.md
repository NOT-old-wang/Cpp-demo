[资料](https://www.cnblogs.com/haippy/p/3235560.html)
[操作系统限制相关](https://blog.csdn.net/vic_qxz/article/details/82219301?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-12.baidujs&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-12.baidujs)

```
注意： 
1.多次获取互斥量可能会发生死锁，所以我们调用std::recursive_mutex递归锁，允许同一线程多次获得该锁，一般不要使用递归锁，原因：<1.用到递归锁会使得程序的逻辑变复杂，使用到递归锁的程序一般可以简化。<2.递归锁比非递归锁效率低。<3.递归锁的可重入次数是有限的，超过也会报错。 
2.可以使用带超时时间的互斥锁，避免阻塞在等待互斥锁上。 
3.unique_lock: 是一个通用的互斥量封装类。与lock_guard不同，它还支持延迟加锁、时间锁、递归锁、锁所有权的转移并且还支持使用条件变量。这也是一个不可复制的类，但它是可以移动的类。
```

1. 线程操作: 创建，销毁
2. 锁: 互斥, 超时互斥, 递归互斥(带时间， 不带时间)
3. 条件变量: std::condition_variable, std::condition_variable_any
4. 原子变量: std::atomic<T>, 不需要加锁 

## linux 命令
```bash
$ ps -aux | grep <进程名> # 查看进程 pid
$ pstree -p <pid> # 查看线程树
$ top -H -p <pid> # 查看线程cpu占用
```
[top命令](http://www.blogjava.net/DLevin/archive/2014/12/31/421982.html)