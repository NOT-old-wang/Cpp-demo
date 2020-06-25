
#include <gperftools/profiler.h>
#include <signal.h>

#include <iostream>

int sub_fun() {
  int n = 0;
  int i = 0, j = 0;
  for (i = 0; i < 1000; i++) {
    n += i + 1;
  }
  return n;
}

int fun() {
  int n = 0;
  int i = 0, j = 0;
  for (i = 0; i < 10000; i++)
    for (j = 0; j < 100; j++) {
      n |= i % 100 + j / 100;
    }
  sub_fun();
  return n;
}

int main(int argc, char *argv[]) {
  ProfilerStart("out.prof");
  int num = fun();  // 应用程序代码
  std::cout << num << std::endl;
  ProfilerStop();
  return 0;
}