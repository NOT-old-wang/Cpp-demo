#include <fstream>
#include <iostream>
#include "gflags/gflags.h"
#include "glog/logging.h"

#define NDEBUG
#include <assert.h>

void SignalHandle(const char* data, int size);
void fun();

int main(int argc, char** argv) {
  // gfalg 和 glog配合使用, 如 ./glog_demo -stderrthreshold=1
  google::ParseCommandLineFlags(&argc, &argv, true);
  // glog 初始化
  google::InitGoogleLogging(argv[0]);

  // 设置输出等级
  // FLAGS_stderrthreshold = google::INFO;
  // google::SetStderrLogging(google::INFO);

  // 开终端日志颜色： 白，黄，红，红
  FLAGS_colorlogtostderr = true;

  // 1) 等级控制
  LOG(INFO) << "info log test.";
  LOG(WARNING) << "warning log test.";
  LOG(ERROR) << "error log test.";
  // LOG(FATAL) << "fatal log test.";

  DLOG(INFO) << "debug info log test.";
  DLOG(WARNING) << "debug warning log test.";
  DLOG(ERROR) << "debug error log test.";
  // DLOG(FATAL) << "debug fatal log test.";

  // 2) 条件控制
  for (int i = 0; i < 10; i++) {
    LOG_IF(WARNING, i == 9) << "i == 9";
  }

  for (int i = 1; i < 10; i++) {
    LOG_EVERY_N(ERROR, 3) << "每隔3次输出一次 " << i;
    LOG_FIRST_N(ERROR, 2) << "前两次输出 " << i;
    LOG_IF_EVERY_N(WARNING, 1 < 2, 2) << "条件输出+频率" << google::COUNTER;
  }

  // 3) 输出日志文件
  // 把日志同时记录文件，最低级别为INFO  FLAGS_log_dir = "../log/"
  google::SetLogDestination(google::ERROR, "../log/");
  // FLAGS_logtostderr = true;  // 只输出到终端
  // google::LogToStderr();

  // 4) 检测宏
  std::string check_test = "test";
  CHECK_EQ(check_test, "test");  // 如果不相同 终止程序
  CHECK_DOUBLE_EQ(2.0, 2.0);
  CHECK(true) << "oh no";

  // 5) 崩溃处理
  google::InstallFailureSignalHandler();
  google::InstallFailureWriter(&SignalHandle);
  fun();

  google::ShutdownGoogleLogging();
  return 0;
}
void fun() {
  int* p = nullptr;
  std::cout << *p << std::endl;
}

// 将信息输出到单独的文件和 LOG(ERROR)
void SignalHandle(const char* data, int size) {
  std::ofstream fs("../log/glog_dump.log", std::ios::app);
  std::string str = std::string(data, size);
  fs << str;
  fs.close();
  LOG(ERROR) << str;
}