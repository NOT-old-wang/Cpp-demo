# GDB 使用文档
> GDB是一个由GNU开源组织发布的、UNIX/LINUX操作系统下的、基于命令行的、功能强大的程序调试工具。 对于一名Linux下工作的c/c++程序员，gdb是必不可少的工具
## 编译
```bash
$ gcc -g test.cc -o gdb_test
$ gdb -q test # 表示不打印gdb版本信息，界面较为干净；
```

## 指令
|  命令  |  命令说明  |
|  ----  | ----  |
| file | 装入需要调试的程序 |
| list           | 显示多行源代； 例：l main，l 10                              |
| info           | 显示相关信息；例：i b = info breakpoints                     |
| run | 开始运行程序；例：r |
| start | 开始执行程序,在main函数的第一条语句前面停下来 |
| continue | 继续程序的运行,直到遇到下一个断点 |
| step           | 执行下一条语句,如果该语句为函数调用,则进入函数执行其中的第一条语句 |
| next | 执行下一条语句,如果该语句为函数调用,不会进入函数内部执行(即不会一步步地调试函数内部语句) |
| display | 跟踪查看某个变量,每次停下来都显示它的值 |
| watch | 监视变量值的变化 |
| print | 打印内部变量值 |
| whatis xx | 查看变量信息 |
| backtrace | 查看函数调用信息(堆栈) |
| frame | 查看栈帧 |
| break | break location:在location位置设置断点,改位置可以为某一行,某函数名或者其它结构的地址 |
| delete  断点号 | delete breakpoints 断点号 = clear n：表示清除第n行的断点； disable/enable n表示使得编号为n的断点暂时失效或有效 |
| until+行号 | 运行至某行，不仅仅用来跳出循环； |