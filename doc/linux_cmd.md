## 一些linux的命令

```bash
$ top -H -p pid # 查看进程的详细线程
$ ps -mp pid -o THREAD,tid,time # 显示当前进程下的所有线程列表
$ printf "%x\n" tid # 打印出16进制
$ jstack pid |grep tid -A tid # 打印线程的堆栈信息

$ ulimit -a # 可以查看处理器的一些性能，比如core文件的大小
$ ulimit -c unlimited # 可以让core文件大小不受限制, 限制为1k: ulimit -c 1024

$ du -sh # 查看文件大小
```

## 参考资料
[ulimit 的功能和用法](https://blog.csdn.net/thinkmore1314/article/details/16341531)