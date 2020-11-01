#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

/*
进程A： a.c
     1) 获得key, ftok()
     2) 使用key来创建一个共享内存 shmget()
     3) 映射共享内存 (得到虚拟地址), shmat()
     4) 使用共享内存， 往共享内存中写入数据
     5) 解除映射 shmdt()
     6) 如果共享内存不再使用，可以使用shmctl()销毁共享内存
*/

int main(int argc, const char **argv) {
  // 生成一个key
  key_t key = ftok("./", 66);
  // 创建共享内存，返回一个id
  int shmid = shmget(key, 8, IPC_CREAT | 0666 | IPC_EXCL);
  if (-1 == shmid) {
    perror("shmget failed");
    exit(1);
  }
  printf("shmid id: %d\n", shmid);
  // 映射共享内存，得到虚拟地址
  void *p = shmat(shmid, 0, 0);
  if ((void *)-1 == p) {
    perror("shmat failed");
    exit(2);
  }
  // 写共享内存
  int *pp = (int *)p;
  *pp = 0x12345678;
  *(pp + 1) = 0xffffffff;
  // 解除映射
  if (-1 == shmdt(p)) {
    perror("shmdt failed");
    exit(3);
  }
  printf("解除映射成功，点击回车销毁共享内存\n");
  getchar();
  // 销毁共享内存
  if (-1 == shmctl(shmid, IPC_RMID, NULL)) {
    perror("shmctl failed");
    exit(4);
  }
  return 0;
}
