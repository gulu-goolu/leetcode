//
// Created by chj on 2020/7/3.
//

#include <iostream>
#include <vector>

// https://leetcode-cn.com/problems/add-two-numbers/

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

// 递归
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return helper(0, l1, l2);
  }

  ListNode* helper(int val, ListNode* l1, ListNode* l2) {
    if (!l1 && !l2 && !val) {
      return nullptr;
    }
    if (l1) {
      val += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      val += l2->val;
      l2 = l2->next;
    }

    auto n = new ListNode(val % 10);
    n->next = helper(val / 10, l1, l2);
    return n;
  }
};

ListNode* build_list(const std::vector<int>& l) {
  ListNode dummy(0);
  ListNode* tail = &dummy;
  for (auto& n : l) {
    tail->next = new ListNode(n);
    tail = tail->next;
  }

  return dummy.next;
}

void show_list(const ListNode* l) {
  while (l) {
    std::cout << l->val;
    l = l->next;
  }
}

int main() {
  auto l1 = build_list({2, 4, 3});
  auto l2 = build_list({5, 6, 4});
  auto l3 = Solution().addTwoNumbers(l1, l2);
  show_list(l3);
}
