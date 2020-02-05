#include <iostream>
#include <vector>

/*O(n 2)*/
void BubbleSort(std::vector<int> *nums) {
  for (int i = 0; i < nums->size(); i++) {
    for (int j = i; j < nums->size(); j++) {
      if ((*nums)[i] > (*nums)[j]) {
        int temp = (*nums)[i];
        (*nums)[i] = (*nums)[j];
        (*nums)[j] = temp;
      }
    }
  }
}

int main(int argc, const char** argv) {
  std::vector<int> test{3, 4, 2, 1, 9, 6, 5, 8 ,7};
  BubbleSort(&test);
  for (int num : test) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}