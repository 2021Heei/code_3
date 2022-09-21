#include "Queue.h"

//��ʼ��
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//���ٶ���
void QueueDestroy(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		QNode* del = cur;
		cur = cur->next;
		free(del);
	}
	/*while (cur) {
		QNode* later = cur->next;
		free(cur);
		cur = later;
	}*/
}

//�����
void QueuePush(Queue* pq, QDataType val) {
	assert(pq);
	//�����½ڵ㣬����ʧ�ܾ��˳�����
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode) {
		perror("QueuePush");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;
	//����β���Ϊ���������
	//1.��ͷָ��Ϊ��
	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	//2.��ͷָ�벻Ϊ��
	else {
		//������ǰ��ڵ㣬�ڸ���β�ڵ�
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	++pq->size;
}

//������
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	//��ֹtailҰָ��
	if (pq->head == pq->tail) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else {
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
		del = NULL;
	}
	--pq->size;
}

//ȡ��ͷ����
QDataType QueueHead(Queue* pq) {
	assert(pq);
	return pq->head->val;
}

//ȡ��β����
QDataType QueueTail(Queue* pq) {
	assert(pq);
	return pq->tail->val;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

//������г���
int QueueSize(Queue* pq) {
	assert(pq);
	//��������Ч�ʽϵ�
	/*int n = 0;
	QNode* cur = pq->head;
	while (cur) {
		++n;
		cur = cur->next;
	}
	return n;*/

	/*ֱ���ڶ��нṹ���ﶨ��һ��size��ÿ������л������ͬʱ�ı�size��
	ʹ��ʱֱ�Ӵӽṹ���ڷ��ؼ���*/
	return pq->size;
}