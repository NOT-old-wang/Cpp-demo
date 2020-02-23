#include <stdio.h>
#include <iostream>

int g_value_1;
int g_value_2 = 0;
static int g_static_value_1;
static int g_static_value_2 = 0;

void fun() {
  int fun_value_1;
  int fun_value_2 = 0;
  printf("fun_value_1 address: %p\n", &fun_value_1);
  printf("fun_value_2 address: %p\n", &fun_value_2);
}

int main(int argc, char** argv) {
  static int static_value_3 = 0;
  int value_1;
  int value_2 = 0;
  // int *p = malloc(sizeof(int));
  printf("g_value_1 address: %p\n", &g_value_1);
  printf("g_value_2 address: %p\n", &g_value_2);
  printf("g_static_value_1 address: %p\n", &g_static_value_1);
  printf("g_static_value_2 address: %p\n", &g_static_value_2);
  printf("static_value_3 address: %p\n", &static_value_3);
  printf("value_1 address: %p\n", &value_1);
  printf("value_2 address: %p\n", &value_2);
  //  printf("p address: %p\n", &p);
  fun();
  return 0;
}

/*
可知 
1: 全局变量和静态变量都放在一块存储区(初始化和未初始化的没有分开?) --》 全局静态
2: 函数里的变量放在一块存储区 --》 栈
3: 手动申请的变量 ？
*/