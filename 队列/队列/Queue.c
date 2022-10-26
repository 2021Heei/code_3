//#include "Queue.h"
//
////��ʼ������
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
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
//
////��β�����
//void QueuePush(Queue* pq, QEDataType val) {
//	assert(pq);
//	//���½ڵ�
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (!newnode) {
//		perror("malloc file");
//		exit(-1);
//	}
//	newnode->val = val;
//	newnode->next = NULL;
//
//	//��ͷָ��Ϊ�ջ�Ϊ��
//	if (pq->head == NULL) {
//		pq->head = pq->tail = newnode;
//	}
//	else {
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//	++pq->size;
//}
//
////��ͷ������
//void QueuePop(Queue* pq) {
//	assert(pq);
//	//�����һ���ڵ㣬��βָ����Ҫ���⴦��һ��
//	if (pq->head->next == NULL) {
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else {
//		QNode* del = pq->head;
//		pq->head = pq->head->next;
//		free(del);
//	}	
//	--pq->size;
//}
//
////ȡ��ͷ����
//QEDataType QueueHead(Queue* pq) {
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->val;
//}
//
////ȡ��β����
//QEDataType QueueTail(Queue* pq) {
//	assert(pq); 
//	assert(!QueueEmpty);
//	return pq->tail->val;
//}
//
////�ж϶����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq) {
//	assert(pq);
//	return pq->head == NULL && pq->tail == NULL;
//}
//
////�������Ԫ�ظ���
//int QueueSize(Queue* pq) {
//	assert(pq);
//	return pq->size;
//}