#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

constexpr char kFileame[] = "mmap.txt";

struct Student {
  int age;
  char name[20];
  char sex;
};

// 这个进程用于创建映射区进行写。
int main(int argc, char *argv[]) {
  Student student = {1, "xiaoming", 'm'};

  int fd = open(kFileame, O_RDWR | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) {
    perror("open");
    return -1;
  }

  ftruncate(fd, sizeof(Student));  //文件拓展大小。

  //创建一个结构体大小的共享映射区。共享映射区我们可以当做数组区看待。
  Student *p = (Student *)mmap(NULL, sizeof(Student), PROT_READ | PROT_WRITE,
                               MAP_SHARED, fd, 0);

  if (p == MAP_FAILED) {
    perror("mmap");
    return -1;
  }
  close(fd);  //关闭不用的文件描述符。

  memcpy(p, &student, sizeof(student));
  while (1) {
    p->age++;
    sleep(1);
  }

  int ret = munmap(p, sizeof(student));
  if (ret < 0) {
    perror("mmumap");
    return -1;
  }

  return 0;
}