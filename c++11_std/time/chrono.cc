#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

int main() {
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  std::time_t yesterday =
      std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
  std::cout << "24 hours ago, the time is "
            << std::put_time(std::localtime(&yesterday), "%F %T") << '\n';

  std::chrono::steady_clock::time_point start =
      std::chrono::steady_clock::now();

  std::this_thread::sleep_for(std::chrono::milliseconds(1));

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Printing took "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "us.\n";
}