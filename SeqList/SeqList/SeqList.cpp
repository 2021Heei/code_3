//#include "SeqList.h"
//
////
//ListNode* GetNewNode(SLDataType val) {
//	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//	if (newnode == NULL) {
//		perror("GetNewNode");
//		exit(-1);
//	}
//	newnode->val = val;
//	newnode->next = NULL;
//}
//
////头插
//void CreateListFromHead(LinkList& L, int n){
//	LinkList head = L;
//	while (n--) {
//		int val = 0;
//		scanf("%d", &val);
//		ListNode* newnode = GetNewNode(val);
//		//链表为空特殊处理
//		if (head == NULL) {
//			head = newnode;
//		}
//		else {
//			newnode->next = head;
//			head = newnode;
//		}
//	}
//	L = head;
//}
//
////尾插
//void CreateListFromTail(LinkList& L, int n){
//	LinkList head = L;
//	while (n--) {
//		int val = 0;
//		scanf("%d", &val);
//		ListNode* newnode = GetNewNode(val);
//		//链表为空特殊处理
//		if (head == NULL) {
//			head = newnode;
//		}
//		else {
//			//找尾
//			ListNode* tail = head;
//			while (tail->next) {
//				tail = tail->next;
//			}
//			tail->next = newnode;
//		}
//	}
//	L = head;
//}
//
////输出
//void PrintList(LinkList L){
//	LinkList cur = L;
//	while (cur) {
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
////销毁
//void DestroyList(LinkList& L){
//	LinkList cur = L;
//	while (cur) {
//		LinkList del = cur;
//		cur = cur->next;
//		free(del);
//	}
//	L = NULL;
//}