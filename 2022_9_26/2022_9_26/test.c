//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//typedef struct ListNode ListNode;
//
//ListNode* BuyNode(int val) {
//    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//    if (newnode == NULL) {
//        return NULL;
//    }
//    newnode->val = val;
//    newnode->next = NULL;
//    return newnode;
//}
//
//ListNode* CreatList(int n) {
//    ListNode* head = BuyNode(1);
//    ListNode* tail = head;
//    for (int i = 2; i <= n; ++i) {
//        tail->next = BuyNode(i);
//        tail = tail->next;
//    }
//    //单向循环链表
//    tail->next = head;
//    return head;
//}
//
//int ysf(int n, int m) {
//    // write code here
//    ListNode* head = CreatList(n);
//    while (head->next != head) {
//        for (int i = 1; i < m; i++) {
//            head = head->next;
//        }
//        ListNode* del = head->next;
//        head->val = del->val;
//        head->next = del->next;
//        free(del);
//    }
//    int ret = head->val;
//    free(head);
//    return ret;
//}
//
//int main() {
//    int n = 1;
//    int m = 1;
//    int r = ysf(n, m);
//    printf("%d \n", r);
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

//int cmp(void* e1, void* e2) {
//    return *((int*)e1) - *((int*)e2);
//}
//int maxProfit(int* prices, int pricesSize) {
//    int* arr = (int*)malloc(sizeof(int) * pricesSize);
//    for (int i = 0; i < pricesSize; ++i) {
//        arr[i] = prices[i];
//    }
//    qsort(arr, pricesSize, sizeof(int), cmp);
//    int sum = 0;
//    for (int i = 0; i < pricesSize; ++i) {
//        int pre = arr[i];
//        int next = 0;
//        int index = 0;
//        for (int j = 0; j < pricesSize; ++j) {
//            if (arr[i] == prices[j]) {
//                index = j;
//                break;
//            }
//        }
//        for (int k = index + 1; k < pricesSize; ++k) {
//            if (prices[k] > next) {
//                next = prices[k];
//            }
//        }
//        if (sum < next - pre) {
//            sum = next - pre;
//        }
//    }
//    return sum;
//}

int maxProfit(int* prices, int pricesSize) {
    int sum = 0;
    int tmp = 0;
    for (int i = 0; i < pricesSize; ++i) {
        tmp = 0;
        int max = 0;
        for (int j = i + 1; j < pricesSize; ++j) {
            if (max < prices[j]) {
                max = prices[j];
            }
        }
        tmp = max - prices[i];
        if (sum < tmp) {
            sum = tmp;
        }
    }
    return sum;
}

int main() {
    
    int a[] = { 7,1,5,3,6,4 };
    int ret = maxProfit(a, sizeof(a) / sizeof(a[0]));
    printf("%d\n", ret);
    return 0;
}