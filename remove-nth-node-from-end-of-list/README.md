注意边界检查即可；
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n <= 0) {
        return head;
    }
    ListNode* ptr = head;
    int m = 0;
    while (ptr) {
        m++;
        ptr = ptr->next;
    }
    
    if (n > m) {
        return head;
    }
    
    // 找到待移除的节点
    ListNode* prev = nullptr;
    ptr = head;
    int i = 0;
    const int k = m - n;
    while (i++ != k) {
        prev = ptr;
        ptr = ptr->next;
    }
    // 如果被移除的是 head 节点
    if (head == ptr) {
        head = ptr->next;
    }
    // 将 prev 指向 next
    if (prev) {
        ListNode* next = nullptr;
        if (ptr) {
            next = ptr->next;
        }
        prev->next = next;
    }
    
    return head;
}
```