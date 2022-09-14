//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdbool.h>
//
//typedef char STDataType;
//typedef struct Stack {
//	STDataType* data;
//	int pop;
//	int capacity;
//}ST;
//
////��ʼ��
//void StackInit(ST* pst);
//
////����ջ
//void StackDestroy(ST* pst);
//
////��ջ
//void StackPush(ST* pst, STDataType val);
//
////��ջ
//void StackPop(ST* pst);
//
////ȡ��ջ��Ԫ��
//STDataType StackTop(ST* pst);
//
////�ж�ջ�Ƿ��ǿ�
//bool StackEmpty(ST* pst);
//
////����ջ�Ĵ�С
//int StackSize(ST* pst);
//
////��ʼ��
//void StackInit(ST* pst) {
//	assert(pst);
//	pst->data = NULL;
//	pst->pop = pst->capacity = 0;
//}
//
////����ջ
//void StackDestroy(ST* pst) {
//	assert(pst);
//	free(pst->data);
//	pst->pop = pst->capacity = 0;
//}
//
////��ջ
//void StackPush(ST* pst, STDataType val) {
//	assert(pst);
//	//����
//	if (pst->pop == pst->capacity) {
//		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(pst->data, sizeof(STDataType) * newCapacity);
//		if (!tmp) {
//			perror("StackPush");
//		}
//		pst->data = tmp;
//		pst->capacity = newCapacity;
//	}
//	pst->data[pst->pop] = val;
//	++pst->pop;
//}
//
////��ջ
//void StackPop(ST* pst) {
//	assert(pst);
//	assert(!StackEmpty(pst));
//	--pst->pop;
//}
//
////ȡ��ջ��Ԫ��
//STDataType StackTop(ST* pst) {
//	assert(pst);
//	return pst->data[pst->pop - 1];
//}
//
////�ж�ջ�Ƿ��ǿ�
//bool StackEmpty(ST* pst) {
//	assert(pst);
//	return pst->pop == 0;
//}
//
////����ջ�Ĵ�С
//int StackSize(ST* pst) {
//	assert(pst);
//	return pst->pop;
//}
//
//
//bool isValid(char* s) {
//	ST obj;
//	StackInit(&obj);
//	while (*s) {
//		//�����ž���ջ
//		if (*s == '(' || *s == '[' || *s == '{') {
//			StackPush(&obj, *s);
//		}
//		else {
//			//��������ʱƥ��ͼ���ѭ������ƥ��ͷ���false
//				//������ʱ��Ҫȡջ��Ԫ�ؽ��бȽϣ�ջ��ȴΪ��
//			if (StackEmpty(&obj)) {
//				StackDestroy(&obj);
//				return false;
//			}
//			if ((*s == ')' && StackTop(&obj) != '(')
//				|| (*s == ']' && StackTop(&obj) != '[')
//				|| (*s == '}' && StackTop(&obj) != '{')) {
//				StackDestroy(&obj);
//				return false;
//			}
//			else {
//				StackPop(&obj);
//			}
//		}
//		++s;
//	}
//	//����������ȫƥ���ջ���Ӧ��Ϊ�գ������Ϊ�վ����������Ų�ƥ��
//	int flag = StackEmpty(&obj);
//	return flag;
//}
//
//
//typedef struct {
//
//} MyStack;
//
//
//MyStack* myStackCreate() {
//
//};
//
//void myStackPush(MyStack* obj, int x) {
//
//}
//
//int myStackPop(MyStack* obj) {
//
//}
//
//int myStackTop(MyStack* obj) {
//
//}
//
//bool myStackEmpty(MyStack* obj) {
//
//}
//
//void myStackFree(MyStack* obj) {
//
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/
//
//
////������ʽ�Ķ���ʵ��
////��װΪ�ڵ�
//typedef int QDataType;
//typedef struct QueueNode {
//	QDataType val;
//	struct QueueNode* next;
//}QNode;
//
////��װ�ڵ�ָ��Ϊ
//typedef struct Queue {
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//
////��ʼ��
//void QueueInit(Queue* pq);
//
////���ٶ���
//void QueueDestroy(Queue* pq);
//
////�����
//void QueuePush(Queue* pq, QDataType val);
//
////������
//void QueuePop(Queue* pq);
//
////ȡ��ͷ����
//QDataType QueueHead(Queue* pq);
//
////ȡ��β����
//QDataType QueueTail(Queue* pq);
//
////�ж϶����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq);
//
////������г���
//int QueueSize(Queue* pq);
//
//
////��ʼ��
//void QueueInit(Queue* pq) {
//	assert(pq);
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
////���ٶ���
//void QueueDestroy(Queue* pq) {
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur) {
//		QNode* del = cur;
//		cur = cur->next;
//		free(del);
//	}
//	/*while (cur) {
//		QNode* later = cur->next;
//		free(cur);
//		cur = later;
//	}*/
//}
//
////�����
//void QueuePush(Queue* pq, QDataType val) {
//	assert(pq);
//	//�����½ڵ㣬����ʧ�ܾ��˳�����
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (!newnode) {
//		perror("QueuePush");
//		exit(-1);
//	}
//	newnode->val = val;
//	newnode->next = NULL;
//	//����β���Ϊ���������
//	//1.��ͷָ��Ϊ��
//	if (pq->head == NULL) {
//		pq->head = pq->tail = newnode;
//	}
//	//2.��ͷָ�벻Ϊ��
//	else {
//		//������ǰ��ڵ㣬�ڸ���β�ڵ�
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//	++pq->size;
//}
//
////������
//void QueuePop(Queue* pq) {
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	//��ֹtailҰָ��
//	if (pq->head == pq->tail) {
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else {
//		QNode* del = pq->head;
//		pq->head = pq->head->next;
//		free(del);
//		del = NULL;
//	}
//	--pq->size;
//}
//
////ȡ��ͷ����
//QDataType QueueHead(Queue* pq) {
//	assert(pq);
//	return pq->head->val;
//}
//
////ȡ��β����
//QDataType QueueTail(Queue* pq) {
//	assert(pq);
//	return pq->tail->val;
//}
//
////�ж϶����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq) {
//	assert(pq);
//	return pq->head == NULL && pq->tail == NULL;
//}
//
////������г���
//int QueueSize(Queue* pq) {
//	assert(pq);
//	//��������Ч�ʽϵ�
//	/*int n = 0;
//	QNode* cur = pq->head;
//	while (cur) {
//		++n;
//		cur = cur->next;
//	}
//	return n;*/
//
//	/*ֱ���ڶ��нṹ���ﶨ��һ��size��ÿ������л������ͬʱ�ı�size��
//	ʹ��ʱֱ�Ӵӽṹ���ڷ��ؼ���*/
//	return pq->size;
//}
//
////��������ģ��ջ
//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&obj->q1);
//	QueueInit(&obj->q2);
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	//�������У���ʼ��Ϊ�գ�������ʱ��ֻ��һ������������
//	if (!QueueEmpty(&obj->q1)) {
//		QueuePush(&obj->q1, x);
//	}
//	else {
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	//��֪���ĸ����������ݣ����Ǽ��跨
//	Queue* Empty = &obj->q1;
//	Queue* NonEmpty = &obj->q2;
//	if (!QueueEmpty(&obj->q1)) {
//		NonEmpty = &obj->q1;
//		Empty = &obj->q2;
//	}
//
//	//�����ݶ���ѭ�����������ݶ��У��������ݶ���ֻʣһ��Ԫ�أ������ݾ�����ɾ����
//	while (QueueSize(NonEmpty) > 1) {
//		QueuePush(Empty, QueueHead(NonEmpty));
//		QueuePop(NonEmpty);
//	}
//	int tmp = QueueHead(NonEmpty);
//	QueuePop(NonEmpty);
//	return tmp;
//}
//
//int myStackTop(MyStack* obj) {
//	//��֪���ĸ����������ݣ����Ǽ��跨
//	Queue* Empty = &obj->q1;
//	Queue* NonEmpty = &obj->q2;
//	if (!QueueEmpty(&obj->q1)) {
//		NonEmpty = &obj->q1;
//		Empty = &obj->q2;
//	}
//	return QueueTail(NonEmpty);
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//	free(obj);
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/
