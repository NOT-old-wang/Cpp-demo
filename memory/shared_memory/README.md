# 共享内存
## 概要
- 内核管理一片物理内存，允许不同的进程同时映射，多个进程可以映射同一块内存，被多个进程同时映射的物理内存，即共享内存

## 特点
```
优点: 是最快的IPC,因为它少了两次拷贝,直接操作同一片内存即可
缺点: 要编程者自己实现对共享内存互斥访问  --> 信号量,引用计数
```

## linux 内存
- 在Linux中，每个进程都有属于自己的进程控制块（PCB）和地址空间（Addr Space），并且都有一个与之对应的页表，负责将进程的虚拟地址与物理地址进行映射，通过内存管理单元（MMU）进行管理。两个不同的虚拟地址通过页表映射到物理空间的同一区域，它们所指向的这块区域即共享内存。

## 补充知识
- ipcs -m: 查看系统中的共享存储段
- shmid: 共享内存id
- 在操作系统中，申请内存的最小单位为页，一页是4k字节, 

## 参考
[参考1](https://www.pianshen.com/article/9764677775/;jsessionid=5AEF1C11D44231561E16DF4E07AEA23E)
[参考2](https://blog.csdn.net/mw_nice/article/details/82888082?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3)
[深度](https://blog.csdn.net/weixin_30483495/article/details/98910014?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1)


```c
/* 创建共享内存:
int shmget(key_t key, size_t size, int shmflg);
[参数key]：由ftok生成的key标识，标识系统的唯一IPC资源。
[参数size]：需要申请共享内存的大小。在操作系统中，申请内存的最小单位为页，一页是4k字节，为了避免内存碎片，我们一般申请的内存大小为页的整数倍。
[参数shmflg]：如果要创建新的共享内存，需要使用IPC_CREAT，IPC_EXCL，如果是已经存在的，可以使用IPC_CREAT或直接传0。
[返回值]：成功时返回一个新建或已经存在的共享内存标识符shmid，取决于shmflg的参数。失败返回-1并设置错误码。
*/

/* 映射共享内存，得到虚拟地址:
void *shmat(int shmid, const void *shmaddr, int shmflg);
[参数shmid]：共享存储段的标识符。
[参数*shmaddr]：shmaddr = 0，则存储段连接到由内核选择的第一个可以地址上（推荐使用）
[参数shmflg]：若指定了SHM_RDONLY位，则以只读方式连接此段，否则以读写方式连接此段。
[返回值]：成功返回共享存储段的指针（虚拟地址），并且内核将使其与该共享存储段相关的shmid_ds结构中的shm_nattch计数器加1（类似于引用计数）出错返回-1
*/

/* 解除内存映射
int shmdt(const void *shmaddr);
[参数*shmaddr]：连接以后返回的地址, 共享内存。
[返回值]：成功返回0，并将shmid_ds结构体中的 shm_nattch计数器减1；出错返回-1。
*/

/* 销毁共享内存
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
[参数shmid]：共享存储段标识符。
[参数cmd]：指定的执行操作，设置为IPC_RMID时表示可以删除共享内存。
[参数*buf]：设置为NULL即可。
[返回值]：成功返回0，失败返回-1。
*/

```