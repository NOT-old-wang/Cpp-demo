#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

/*
进程B： b.c
　　1) 获得key, ftok()
　　2) 使用key来获得一个共享内存 shmget()
　　3) 映射共享内存（得到虚拟地址）， shmat()
　　4) 使用共享内存， 读取共享内存中的数据
　　5) 解除映射 shmdt()
*/

int main(int argc, const char **argv) {
  // 生成一个key
  key_t key = ftok(".", 66);
  // 获取共享内存，返回一个id
  int shmid = shmget(key, 0, 0);
  if (-1 == shmid) {
    perror("shmget failed");
    exit(1);
  }
  // 映射共享内存，得到虚拟地址
  void *p = shmat(shmid, 0, 0);
  if ((void *)-1 == p) {
    perror("shmat failed");
    exit(2);
  }
  // 读共享内存
  int x = *(int *)p;
  int y = *((int *)p + 1);
  printf("从共享内存中都取了：0x%x 和 0x%x \n", x, y);
  // 解除映射
  if (-1 == shmdt(p)) {
    perror("shmdt failed");
    exit(3);
  }
  return 0;
}