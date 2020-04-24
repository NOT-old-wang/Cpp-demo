#include <iostream>
#include <tuple>

int main(int argc, const char** argv) {
  std::tuple<int, std::string> my_tuple;

  my_tuple = std::make_tuple(1, "string");
  std::cout << std::get<1>(my_tuple) << std::endl;

  int num;
  std::tie(num, std::ignore) = my_tuple;
  std::cout << num << std::endl;

  int size =  std::tuple_size<decltype(my_tuple)>::value;
  std::cout << size << std::endl;
}