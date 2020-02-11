#include <iostream>
#include <vector>

struct ListNode {
  ListNode* next;
  int val;
  ListNode(int value) : val(value), next(nullptr) {};
};

void Print(ListNode* list) {
  while (list != nullptr) {
    std::cout << list->val << ", ";
    list = list->next;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}

ListNode* Create(const std::vector<int> nums) {
  ListNode dummy_head(0);
  ListNode* p = &dummy_head;
  for (int num : nums) {
    p->next = new ListNode(num);
    p = p->next;
  }
  return dummy_head.next;
}

ListNode* Reverse(ListNode* list) {
  ListNode* pre = nullptr;
  ListNode* cur = list;
  while (cur != nullptr) {
    ListNode* temp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = temp; 
  }
  return pre;
}

int main(int argc, const char** argv) {
  ListNode* list = Create({1, 2, 3, 4, 5, 6});
  Print(Reverse(list));
}