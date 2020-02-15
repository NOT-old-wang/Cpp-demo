#include <iostream>
#include "glog/logging.h"

int main(int argc, char **argv) {
  // glog 初始化
  google::InitGoogleLogging(argv[0]);

  // 设置输出等级
  // FLAGS_stderrthreshold = google::INFO;
  google::SetStderrLogging(google::INFO);

  // 开终端日志颜色： 白，黄，红，红
  FLAGS_colorlogtostderr = true;

  // 把日志同时记录文件，最低级别为INFO  FLAGS_log_dir = "../log/"
  google::SetLogDestination(google::ERROR, "../log/");
  // FLAGS_logtostderr = true;  // 只输出到终端
  // google::LogToStderr();

  LOG(INFO) << "info log test.";
  LOG(WARNING) << "warning log test.";
  LOG(ERROR) << "error log test.";
  // LOG(FATAL) << "fatal log test.";

  for (int i = 0; i < 10; i++) {
    LOG_IF(WARNING, i == 9) << "i == 9";
  }

  // LOG_EVERY_N(ERROR, 3) << "每隔3次输出一次 " << i;
  // LOG_FIRST_N(ERROR, 2) << "前两次输出 " << i;
  // LOG_IF_EVERY_N(WARNING, 1 < 2, 2) << "条件输出+频率" << google::COUNTER;

  google::ShutdownGoogleLogging();
  return 0;
}