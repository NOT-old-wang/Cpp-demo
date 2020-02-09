#include <iostream>
#include <vector>

// 在有序数组里查找
int BinarySearch(std::vector<int> nums, int value) {
  if (nums.empty()) return -1;
  int left = 0;
  int right = nums.size() - 1;
  int mid = 0;
  while (left <= right) {
    mid = left + ((right - left) / 2);

    if (value > nums[mid]) {
      left = mid + 1;
    } else if (value < nums[mid]) {
      right = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main(int argc, const char** argv) {
  std::vector<int> nums1{1, 2, 3, 4, 5, 6};
  std::cout << BinarySearch(nums1, 3) << std::endl;

  std::vector<int> nums2{1, 2, 3, 4, 5};
  std::cout << BinarySearch(nums2, 0) << std::endl;
}