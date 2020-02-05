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

// 归并l1 l2 两个有序链表
ListNode* Merge(ListNode* l1, ListNode* l2) {
  ListNode dummyHead(0);
  auto p = &dummyHead;
  while (l1 && l2) {
    if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;       
    } else {
        p->next = l2;
        l2 = l2->next;
    }
    p = p->next;
  }
  p->next = l1 == nullptr ? l2 : l1;
  return dummyHead.next;
}

// 切除前n个节点
ListNode* Cut(ListNode* head, int n) {
  if (n <= 0) return head;
  ListNode* pre = head;
  int next_count = 1;
  while (pre != nullptr) {
    if (next_count == n) break;
    next_count++;
    pre = pre->next;
  }
  if (pre == nullptr) return nullptr;
  ListNode* p = pre->next;
  pre->next = nullptr;
  return p;
}

ListNode* BottomToUp(ListNode* list) {
  if (nullptr == list) return nullptr;
  int len = 0;
  ListNode* p = list;
  while (p != nullptr) {
    len ++;
    p = p->next;
  }
  ListNode dummy_head(0);
  dummy_head.next = list;
  for (int size = 1; size < len; size <<= 1) {
    ListNode* cur = dummy_head.next;
    ListNode* work = &dummy_head;
    while (cur != nullptr) {
      ListNode* left = cur;
      ListNode* right = Cut(left, size);
      cur = Cut(right, size);

      work->next = Merge(left, right);
      while (work->next != nullptr) {
        work = work->next;
      }
    }
  }
  return dummy_head.next;
}

int main(int argc, const char **argv) {
  std::vector<int> nums{2, 6, 4, 55, 13, 0, 9, 1};
  ListNode* l = Create(nums);
  // ListNode* list = Cut(l, 1);
  // Print(list);
  ListNode* list = BottomToUp(l);
  Print(list);
}