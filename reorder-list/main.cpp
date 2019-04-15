#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void show_list(const char *tag, ListNode *ptr) {
    printf("%s : [", tag);
    while (ptr) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("]\n");
}

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

void reorderList(ListNode *head) {
    // 确保最少有两个节点
    if (!head || !head->next)
        return;
    ListNode *ptr = head;
    ListNode *odd;
    ListNode *even;
    make_odd_even_list(head, &odd, &even);

    show_list("odd", odd);
    show_list("even", even);

    // 翻转 even 链表
    even = reverse(even);

    show_list("reverse", even);

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

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    show_list("initial", head);
    reorderList(head);
	show_list("final", head);
}