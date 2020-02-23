#include <stdio.h>
#include <iostream>

class EmptyClass {};

class TestClass {
 public:
  int value_1;
  char value_2;
  int value_3;

 private:
};

class VirtualClass {
 public:
  virtual void fun() {}

 private:
};

class Virtual2Class : public VirtualClass, public EmptyClass {};

int main(int argc, char** argv) {
  std::cout << "EmptyClass size: " << sizeof(EmptyClass) << std::endl;
  std::cout << "TestClass size: " << sizeof(TestClass) << std::endl;
  std::cout << "VirtualClass size: " << sizeof(VirtualClass) << std::endl;
  std::cout << "Virtual2Class size: " << sizeof(Virtual2Class) << std::endl;

  // 打印类的成员变量地址，其实是每个成员的 offset
  printf("TestClass value_1 address: %p\n", &TestClass::value_1);
  printf("TestClass value_2 address: %p\n", &TestClass::value_2);
  printf("TestClass value_3 address: %p\n", &TestClass::value_3);
  // 对象的地址才是内存里的地址
  TestClass test_class;
  printf("test_class value_1 address: %p\n", &test_class.value_1);
  printf("test_class value_2 address: %p\n", &test_class.value_2);
  printf("test_class value_3 address: %p\n", &test_class.value_3);

  return 0;
}

/*
注意点：
1: 空类都有 1字节的标示
2: 虚函数有相应的 vptr 需要维护, 大小为指针的大小
2: 内寸都有对齐(补齐)操作
*/