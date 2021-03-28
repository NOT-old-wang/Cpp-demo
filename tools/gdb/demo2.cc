#include <sys/prctl.h>
#include <sys/wait.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

bool run;

void Stop(int signo) {
  run = false;
  std::cout << "ctrl c" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

int main(int argc, char **argv) {
  run = true;
  std::mutex mutex;

  std::thread t1([&] {
    prctl(PR_SET_NAME, "thread 1");
    while (run) {
      {
        // std::unique_lock<std::mutex>(mutex);
        // mutex.lock();
        std::cout << "1" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // mutex.unlock();
      }
    }
    std::cout << "thread 1 exit" << std::endl;
  });

  std::thread t2([&] {
    prctl(PR_SET_NAME, "thread 2");
    while (run) {
      // mutex.lock();
      std::cout << "2" << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      // mutex.unlock();
    }
    std::cout << "thread 2 exit" << std::endl;
  });

  std::thread t3([&] {
    prctl(PR_SET_NAME, "thread 3");
    std::cout << "3" << std::endl;
    while (run) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    std::cout << "thread 3 exit" << std::endl;
  });

  signal(SIGINT, Stop);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}