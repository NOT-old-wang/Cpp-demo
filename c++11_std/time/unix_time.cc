#include <iostream>

int main() {
  time_t t = time(nullptr);
  // tm* p_tm = gmtime(&t);  // UTC 时间
  tm* p_tm = localtime(&t);  // 当地时间
  std::cout << t << " = ";
  std::cout << 1900 + p_tm->tm_year << "-";
  std::cout << 1 + p_tm->tm_mon << "-" << p_tm->tm_mday << " ";
  std::cout << p_tm->tm_hour << ":" << p_tm->tm_min << ":" << p_tm->tm_sec
            << std::endl;
  return 0;
}