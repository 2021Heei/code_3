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
////ͷ��
//void CreateListFromHead(LinkList& L, int n){
//	LinkList head = L;
//	while (n--) {
//		int val = 0;
//		scanf("%d", &val);
//		ListNode* newnode = GetNewNode(val);
//		//����Ϊ�����⴦��
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
////β��
//void CreateListFromTail(LinkList& L, int n){
//	LinkList head = L;
//	while (n--) {
//		int val = 0;
//		scanf("%d", &val);
//		ListNode* newnode = GetNewNode(val);
//		//����Ϊ�����⴦��
//		if (head == NULL) {
//			head = newnode;
//		}
//		else {
//			//��β
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
////���
//void PrintList(LinkList L){
//	LinkList cur = L;
//	while (cur) {
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
////����
//void DestroyList(LinkList& L){
//	LinkList cur = L;
//	while (cur) {
//		LinkList del = cur;
//		cur = cur->next;
//		free(del);
//	}
//	L = NULL;
//}