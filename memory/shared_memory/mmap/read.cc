#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

constexpr char kFileame[] = "mmap.txt";

struct Student {
  int age;
  char name[20];
  char sex;
};

// 这个进程读
int main(int argc, char *argv[]) {
  int fd = open(kFileame, O_RDONLY, 0644);
  if (fd < 0) {
    perror("open failed.");
    return -1;
  }

  Student student;
  Student *p =
      (Student *)mmap(NULL, sizeof(Student), PROT_READ, MAP_SHARED, fd, 0);
  if (p == MAP_FAILED) {
    perror("mmap failed.");
    return -1;
  }
  close(fd);

  while (1) {
    printf("id = %d\tname = %s\t%c\n", p->age, p->name, p->sex);
    sleep(1);
  }

  int ret = munmap(p, sizeof(student));
  if (ret < 0) {
    perror("mmumap failed.");
    return -1;
  }

  return 0;
}