#include <iostream>

int g_value;

class ClassValue {
  int value;
};

struct StructValue {
  int vlaue_1;
  int vlaue_2;
};

template <typename T>
int func(T value) {
  return static_cast<int>(value);
}

int main(int argc, char** argv) {
  g_value = 1;
  static float static_value;
  const double const_value = 3;
  ClassValue class_value;
  StructValue struct_value;
  func(g_value);
  return 0;
}

// 编译完成后g_value的值和地址就存在 symbol context中