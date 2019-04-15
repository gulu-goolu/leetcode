没啥技巧，just do it
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k)
            return head;
        int n = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            n++;
        }
        
        int m = n - k % n;
        if (m == n)
            return head;
        ptr = head;
        while (m--) {
            ListNode* prev = ptr;
            ptr = ptr->next;
            if (!m)
                prev->next = nullptr;
        }
        
        ListNode* result = ptr;
        
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = head;
                
        return result;
    }
};
```