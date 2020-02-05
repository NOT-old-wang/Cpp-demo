#include <iostream>
#include <string>
#include <vector>

// 暴力法
int ViolenceMatch(const std::string s, const std::string sub_s) {
  int s_len = s.size();
  int sub_s_len = sub_s.size();

  int i = 0;
  int j = 0;

  while (i < s_len && j < sub_s_len) {
    if (s[i] == sub_s[j]) {
      i++;
      j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j == sub_s_len) {
    return (i - j);
  } else {
    return -1;
  }
}

std::vector<int> GetNext(const std::string s) {}

/*
Knuth-Morris-Pratt 字符串查找算法，简称为 “KMP算法”
常用于在一个文本串S内查找一个模式串P 的出现位置
这个算法由Donald Knuth、Vaughan Pratt、James H.
Morris三人于1977年联合发表，故取这3人的姓氏命名此算法
*/
int KmpMatch(const std::string s, const std::string sub_s) {}

int main(int argc, const char** argv) {
  std::string s = "wangjunyi";
  std::string sub_s = "juy";
  int index = ViolenceMatch(s, sub_s);
  std::cout << index << std::endl;
}