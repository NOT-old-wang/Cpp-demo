
#include <iostream>
#include <vector>

struct ListNode {
  ListNode* next;
  int val;
  ListNode(int value) : val(value), next(nullptr) {};
};

ListNode* Create(const std::vector<int> nums) {
  ListNode dummy_head(0);
  ListNode* p = &dummy_head;
  for (int num : nums) {
    p->next = new ListNode(num);
    p = p->next;
  }
  // 添加环
  p->next = dummy_head.next;

  return dummy_head.next;
}

bool CheckLoopList(ListNode* list) {
  if (nullptr == list) {
    return false;
  }
  ListNode* slow = list;
  ListNode* fast = list->next;
  while (fast != nullptr){
    if (fast == slow) {
      return true;
    } else {
      fast = fast->next;
      if (nullptr == fast) return false;
      slow = slow->next;
      fast = fast->next;
    }
  }
  return true;
}

int main(int argc, const char **argv) {
  std::vector<int> nums{2, 6, 4, 55, 13, 0, 9, 1};
  ListNode* l = Create(nums);
  if (CheckLoopList(l)) {
    std::cout << "loop list" << std::endl;
  }
}