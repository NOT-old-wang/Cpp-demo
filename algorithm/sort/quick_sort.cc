#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& nums, int left, int right);
void QuickSortSwap(std::vector<int>& nums, int left, int right);
void QuickSort(std::vector<int>& nums);

void QuickSort(std::vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;
#if 0
  QuickSort(nums, left, right);
#endif

#if 1
  QuickSortSwap(nums, left, right);
#endif
}

// 选择一个元素作为基数（最右边）
// 把比基数小的元素放到它左边, 比基数大的元素放到它右边（相当于二分）
// 再不断递归基数左右两边的序列
// 本质是给基准数找其正确位置的过程.
void QuickSort(std::vector<int>& nums, int left, int right) {
  if (left >= right) return;
  int cur = left;
  for (int i = 0; i < right; i++) {
    // 右基准 
    if (nums[i] < nums[right]) {
    // nums[cur]之前的数都小于等于nums[right]
      std::swap(nums[cur], nums[i]);
      cur++;
    }
  }
  // 此时cur所指的位置即为num[right]在数组中的对应位置
  std::swap(nums[cur], nums[right]);
  QuickSort(nums, left, --cur);
  QuickSort(nums, ++cur, right);
}

void QuickSortSwap(std::vector<int>& nums, int left, int right) {
  if (left >= right) return;
  // 左基准，从左开始
  int temp = nums[left];
  int p = left + 1;
  int q = right;
  while (p < q) {
    // 向右找到第一个大于基准数的位置
    while (p < q && nums[p] < temp) p++;
    // 向左找到第一个大于基准数的位置
    while (p < q && nums[q] > temp) q--;
    if (p < q) {
      std::swap(nums[p], nums[q]);
      p++;
      q--;
    }
  }
  int index = q;
  std::swap(nums[left], nums[index]);
  QuickSortSwap(nums, left, --index);
  QuickSortSwap(nums, ++index, right);
}

int main(int argc, const char** argv) {
  std::vector<int> test{3, 4, 2, 1, 9, 6, 5, 8, 7};
  QuickSort(test);

  for (int num : test) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}