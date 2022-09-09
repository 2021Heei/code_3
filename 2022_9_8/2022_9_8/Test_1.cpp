#define _CRT_SECURE_NO_WARNINGS 1
//快速单链表构建-基本结构
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

ListNode* partition(ListNode* pHead, int x) {
    // write code here
    ListNode* cur = pHead;
    ListNode* pSmall = NULL;
    ListNode* pBig = NULL;
    ListNode* tail_1 = NULL;
    ListNode* tail_2 = NULL;
    while (cur) {
        if (cur->val < x) {
            if (pSmall == NULL) {
                pSmall = cur;
                tail_1 = pSmall;
            }
            else {
                tail_1->next = cur;
                tail_1 = tail_1->next;
            }

        }
        else {
            if (pBig == NULL) {
                pBig = cur;
                tail_2 = pBig;
            }
            else {
                tail_2->next = cur;
                tail_2 = tail_2->next;
            }
        }
        cur = cur->next;
    }
    if (!pSmall) {
        tail_2->next = NULL;
        tail_1->next = pBig;
        pHead = pSmall;
    }
    else {
        pHead = pBig;
    }
    return pHead;
}

void SListPrint(ListNode* phead) {
    ListNode* cur = phead;
    while (cur) {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}
int main() {
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n1);
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n2);
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n3);
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n4);
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n5);
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n6);
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n7);

	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	/*n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;*/

	n1->val = 6;
	n2->val = 2;
	n3->val = 8;
	/*n4->val = 2;
	n5->val = 6;
	n6->val = 1;
	n7->val = 3;*/
    
    ListNode* phead = n1;
    partition(phead, 9);

    SListPrint(phead);
	return 0;
}

