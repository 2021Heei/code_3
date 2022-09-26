#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

ListNode* BuyNode(int val) {
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    if (newnode == NULL) {
        return NULL;
    }
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

ListNode* CreatList(int n) {
    ListNode* head = BuyNode(1);
    ListNode* tail = head;
    for (int i = 2; i <= n; ++i) {
        tail->next = BuyNode(i);
        tail = tail->next;
    }
    //单向循环链表
    tail->next = head;
    return head;
}

int ysf(int n, int m) {
    // write code here
    ListNode* head = CreatList(n);
    while (head->next != head) {
        for (int i = 1; i < m; i++) {
            head = head->next;
        }
        ListNode* del = head->next;
        head->val = del->val;
        head->next = del->next;
        free(del);
    }
    int ret = head->val;
    free(head);
    return ret;
}

int main() {
    int n = 1;
    int m = 1;
    int r = ysf(n, m);
    printf("%d \n", r);

    return 0;
}