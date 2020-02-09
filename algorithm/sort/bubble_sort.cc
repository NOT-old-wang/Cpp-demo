#include <iostream>
#include <vector>

/*O(n 2)*/
// void BubbleSort(std::vector<int>* nums) {
//   for (int i = 0; i < nums->size(); i++) {
//     for (int j = i; j < nums->size(); j++) {
//       if ((*nums)[i] > (*nums)[j]) {
//         int temp = (*nums)[i];
//         (*nums)[i] = (*nums)[j];
//         (*nums)[j] = temp;
//       }
//     }
//   }
// }

void BubbleSort(std::vector<int>* nums) {
  if (nums->size() <= 1) return;
  // 是否交换完成标志
  bool flag = true;
  int len = nums->size();
  while (flag) {
    flag = false;
    for (int i = 1; i < len; i++) {
      if ((*nums)[i - 1] > (*nums)[i]) {
        std::swap((*nums)[i - 1], (*nums)[i]);
        flag = true;
      }
    }
    len--;
  }
}

int main(int argc, const char** argv) {
  std::vector<int> test{3, 4, 2, 1, 9, 6, 5, 8, 7};
  BubbleSort(&test);
  for (int num : test) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}