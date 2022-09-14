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
////初始化
//void StackInit(ST* pst);
//
////销毁栈
//void StackDestroy(ST* pst);
//
////入栈
//void StackPush(ST* pst, STDataType val);
//
////出栈
//void StackPop(ST* pst);
//
////取出栈顶元素
//STDataType StackTop(ST* pst);
//
////判断栈是否是空
//bool StackEmpty(ST* pst);
//
////返回栈的大小
//int StackSize(ST* pst);
//
////初始化
//void StackInit(ST* pst) {
//	assert(pst);
//	pst->data = NULL;
//	pst->pop = pst->capacity = 0;
//}
//
////销毁栈
//void StackDestroy(ST* pst) {
//	assert(pst);
//	free(pst->data);
//	pst->pop = pst->capacity = 0;
//}
//
////入栈
//void StackPush(ST* pst, STDataType val) {
//	assert(pst);
//	//扩容
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
////出栈
//void StackPop(ST* pst) {
//	assert(pst);
//	assert(!StackEmpty(pst));
//	--pst->pop;
//}
//
////取出栈顶元素
//STDataType StackTop(ST* pst) {
//	assert(pst);
//	return pst->data[pst->pop - 1];
//}
//
////判断栈是否是空
//bool StackEmpty(ST* pst) {
//	assert(pst);
//	return pst->pop == 0;
//}
//
////返回栈的大小
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
//		//左括号就入栈
//		if (*s == '(' || *s == '[' || *s == '{') {
//			StackPush(&obj, *s);
//		}
//		else {
//			//左右括号时匹配就继续循环，不匹配就返回false
//				//右括号时需要取栈里元素进行比较，栈里却为空
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
//	//左右括号完全匹配后栈最后应该为空，如果不为空就是左右括号不匹配
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
////链表形式的队列实现
////封装为节点
//typedef int QDataType;
//typedef struct QueueNode {
//	QDataType val;
//	struct QueueNode* next;
//}QNode;
//
////封装节点指针为
//typedef struct Queue {
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//
////初始化
//void QueueInit(Queue* pq);
//
////销毁队列
//void QueueDestroy(Queue* pq);
//
////入队列
//void QueuePush(Queue* pq, QDataType val);
//
////出队列
//void QueuePop(Queue* pq);
//
////取队头数据
//QDataType QueueHead(Queue* pq);
//
////取队尾数据
//QDataType QueueTail(Queue* pq);
//
////判断队列是否为空
//bool QueueEmpty(Queue* pq);
//
////计算队列长度
//int QueueSize(Queue* pq);
//
//
////初始化
//void QueueInit(Queue* pq) {
//	assert(pq);
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
////销毁队列
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
////入队列
//void QueuePush(Queue* pq, QDataType val) {
//	assert(pq);
//	//申请新节点，申请失败就退出程序
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (!newnode) {
//		perror("QueuePush");
//		exit(-1);
//	}
//	newnode->val = val;
//	newnode->next = NULL;
//	//链表尾插分为两种情况：
//	//1.队头指针为空
//	if (pq->head == NULL) {
//		pq->head = pq->tail = newnode;
//	}
//	//2.队头指针不为空
//	else {
//		//先链接前后节点，在更新尾节点
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//	++pq->size;
//}
//
////出队列
//void QueuePop(Queue* pq) {
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	//防止tail野指针
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
////取队头数据
//QDataType QueueHead(Queue* pq) {
//	assert(pq);
//	return pq->head->val;
//}
//
////取队尾数据
//QDataType QueueTail(Queue* pq) {
//	assert(pq);
//	return pq->tail->val;
//}
//
////判断队列是否为空
//bool QueueEmpty(Queue* pq) {
//	assert(pq);
//	return pq->head == NULL && pq->tail == NULL;
//}
//
////计算队列长度
//int QueueSize(Queue* pq) {
//	assert(pq);
//	//遍历法，效率较低
//	/*int n = 0;
//	QNode* cur = pq->head;
//	while (cur) {
//		++n;
//		cur = cur->next;
//	}
//	return n;*/
//
//	/*直接在队列结构体里定义一个size，每次入队列或出队列同时改变size，
//	使用时直接从结构体内返回即可*/
//	return pq->size;
//}
//
////两个队列模拟栈
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
//	//两个队列，初始都为空，有数据时则只有一个队列有数据
//	if (!QueueEmpty(&obj->q1)) {
//		QueuePush(&obj->q1, x);
//	}
//	else {
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	//不知道哪个队列有数据，仍是假设法
//	Queue* Empty = &obj->q1;
//	Queue* NonEmpty = &obj->q2;
//	if (!QueueEmpty(&obj->q1)) {
//		NonEmpty = &obj->q1;
//		Empty = &obj->q2;
//	}
//
//	//有数据队列循环倒入无数据队列，至有数据队列只剩一个元素，该数据就是所删数据
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
//	//不知道哪个队列有数据，仍是假设法
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
