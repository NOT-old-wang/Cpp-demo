#include <iostream>
#include <vector>

/*O(n 2)*/
void InsertSort(std::vector<int> *nums) {
  for (int i = 0; i < nums->size(); i++) {
    for (int j = i; j > 0; j--) {
      if ((*nums)[j-1] > (*nums)[j]) {
        int temp = (*nums)[j-1];
        (*nums)[j-1] = (*nums)[j];
        (*nums)[j] = temp;
      }
    }
  }
}

int main(int argc, const char** argv) {
  std::vector<int> test{3, 4, 2, 1, 9, 6, 5, 8 ,7};
  InsertSort(&test);
  for (int num : test) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}