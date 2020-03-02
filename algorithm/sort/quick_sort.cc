#include <iostream>
#include <vector>
/*
方法步骤：
1: 将数组分成左右两部份
2: 递归排序左子数组
3: 递归排序右子数组
*/

void QuickSort(std::vector<int>& nums);
// 模式1, 选择一个基准
void QuickSort(std::vector<int>& nums, int left, int right);
// 模式2, 左右同时进行
void QuickSortSwap(std::vector<int>& nums, int left, int right);

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
  for (int i = left; i < right; i++) {
    // 右基准
    if (nums[i] <= nums[right]) {
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
  if(left >= right) return;
	int i = left;
  int j = right;
	int base = nums[left];  //取最左边的数为基准数
	while (i < j) {
		while (nums[j] >= base && i < j)
			j--;
		while (nums[i] <= base && i < j)
			i++;
		if(i < j) {
      std::swap(nums[i], nums[j]);
		}
	}
	//基准数归位
	std::swap(nums[left], nums[i]);
	QuickSortSwap(nums, left, i-1); 
	QuickSortSwap(nums, i+1, right);
}

int main(int argc, const char** argv) {
  std::vector<int> test{3, 1000, 2, 56, 67, 3, 1, 2, 4, 100, 99, 5, 5, 6};
  QuickSort(test);

  for (int num : test) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}