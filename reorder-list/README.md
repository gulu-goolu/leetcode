没啥技巧 just do it
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *next(ListNode *&ptr) {
        ListNode *t = ptr;
        ptr = ptr->next;
        return t;
    }

    void make_odd_even_list(ListNode *ptr, ListNode **podd, ListNode **peven) {
        *podd = next(ptr);
        *peven = next(ptr);

        ListNode *odd = *podd;
        ListNode *even = *peven;

        while (ptr) {
            odd->next = next(ptr);
            even->next = next(ptr);
            odd = odd->next;
            even = even->next;
            if (!odd->next || !even->next)
                break;
        }
        if (odd->next)
            odd->next = nullptr;
    }

    ListNode *reverse(ListNode *ptr) {
        ListNode *prev = nullptr;
        while (ptr) {
            ListNode *next = ptr->next;
            ptr->next = prev;

            prev = ptr;
            ptr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        // 确保最少有两个节点
        if (!head || !head->next)
            return;
        int m = 0;
        ListNode *ptr = head;
        while (ptr) {
            ptr = ptr->next;
            m++;
        }
        
        int mid = (m + 1) / 2;
        
        ListNode *odd = head;
        ptr = head;
        ListNode* prev = nullptr;
        while (mid--) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = nullptr;
        
        ListNode* even = ptr;
        
        // 翻转 even 链表
        even = reverse(even);

        // 合并链表
        while (true) {
            ListNode *odd_next = odd->next;
            ListNode *even_next = even->next;

            odd->next = even;
            even->next = odd_next;

            odd = odd_next;
            even = even_next;

            if (!odd || !even)
                break;
        }
    }
};
```