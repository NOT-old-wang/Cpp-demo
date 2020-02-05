#include <iostream>
#include <vector>

// 从前往后
void Merge(std::vector<int>& nums1, std::vector<int>& nums2,
           std::vector<int>& nums) {
  int len1 = nums1.size();
  int len2 = nums2.size();

  int i = 0;
  int j = 0;
  while (i < len1 && j < len2) {
    if (nums1[i] < nums2[j]) {
      nums.emplace_back(nums1[i]);
      i++;
    } else {
      nums.emplace_back(nums2[j]);
      j++;
    }
  }
  while (i < len1) {
    nums.emplace_back(nums1[i]);
    i++;
  }
  while (j < len1) {
    nums.emplace_back(nums2[j]);
    j++;
  }
}

// 从后往前
void Merge(std::vector<int>& nums1, std::vector<int>& nums2) {
#if 1
  int len1 = nums1.size() - 1;
  int len2 = nums2.size() - 1;
  int len = nums1.size() + nums2.size() - 1;
  while (len1 >= 0 && len2 >= 0) {
    if (nums1[len1] > nums2[len2]) {
      nums1[len--] = nums1[len1--];
    } else {
      nums1[len--] = nums2[len2--];
    }
  }
  while (len2 >= 0) nums1[len--] = nums2[len2--];
#endif
#if 0
 int len1 = nums1.size() - 1;
 int len2 = nums2.size() - 1;
 int len = nums1.size() + nums2.size() - 1;
 while (len2 >= 0) {
   nums1[len--] = len1 > 0 && nums1[len1] > nums2[len2] ? nums1[len1--] : nums2[len2--];
 }
#endif
}

/*O(n 2)*/
std::vector<int> MergeSort(std::vector<int>& nums, int left, int right) {
  if (left > right) return {};  // 左指针大于右指针,直接返回空
  if (left == right) return {nums[left]};  // 归并到单个数直接返回,不做排序
  int mid = left + (right - left) / 2;        // 二分
  auto nums1 = MergeSort(nums, left, mid);       // 左侧归并
  // std::cout << "nums1 size: " << nums1.size() << std::endl;
  auto nums2 = MergeSort(nums, mid + 1, right);  // 右侧归并

  std::vector<int> res;  // 临时数组,返回排序好的部分数组
  // Merge(nums1, nums2, res); ?
  int i = 0;
  int j = 0;
  // 只要有一个数组被遍历完,则跳出循环
  while (i < nums1.size() && j < nums2.size()) {  
    if (nums1[i] <= nums2[j]) {
      res.push_back(nums1[i++]);
    } else {
      res.push_back(nums2[j++]);
    }
  }
  while (i < nums1.size())
    res.push_back(
        nums1[i++]);  // 若右数组被遍历完,则说明左数组剩下的所有数都大于右数组,直接放在临时数组最后
  while (j < nums2.size()) res.push_back(nums2[j++]);  // 同理
  return res;
}

int main(int argc, const char** argv) {
  std::vector<int> test{3, 4, 2, 1, 9, 6, 5, 8, 7};
  for (int num : MergeSort(test, 0, 8)) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}