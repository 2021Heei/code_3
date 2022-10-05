//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <math.h>
//#include <assert.h>
//
//typedef struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//}BTNode;
//
//  //��װΪ�ṹ��
//typedef struct TreeNode* QEDataType;
//typedef struct QNode {
//	QEDataType val;
//	struct QNode* next;
//}QNode;
//
////��װΪ����
//typedef struct Queue {
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//
//
//
////��ʼ������
//void QueueInit(Queue* pq);
//
////���ٶ���
//void QueueDestroy(Queue* pq);
//
////��β�����
//void QueuePush(Queue* pq, QEDataType val);
//
////��ͷ������
//void QueuePop(Queue* pq);
//
////ȡ��ͷ����
//QEDataType QueueHead(Queue* pq);
//
////ȡ��β����
//QEDataType QueueTail(Queue* pq);
//
////�ж϶����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq);
//
////�������Ԫ�ظ���
//int QueueSize(Queue* pq);
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
//
//
//BTNode* CreateTree() {
//	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n1);
//	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n2);
//	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n3);
//	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n4);
//	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
//	assert(n5);
//
//	//��ʼ������ָ��ΪNULL
//	n1->left = n1->right = NULL;
//	n2->left = n2->right = NULL;
//	n3->left = n3->right = NULL;
//	n4->left = n4->right = NULL;
//	n5->left = n5->right = NULL;
//
//	//�ֶ���ֵ
//	/*n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//	n5->val = 5;*/
//	n1->val = 3;
//	n2->val = 9;
//	n3->val = 20;
//	n4->val = 15;
//	n5->val = 7;
//;
//
//	//�ֶ����ƽڵ�����ָ��ָ��
//	/*n1->left = n2;
//	n2->left = n3;
//	n3->left = n4;
//	n4->left = n5;*/
//	n1->left = n2;
//	n1->right = n3;
//	n3->left = n4;
//	n3->right = n5;
//	return n1;
//}
//
//
//int KSize(struct TreeNode* root, int k) {
//	if (root == NULL) {
//		return 0;
//	}
//	if (k == 1) {
//		return 1;
//	}
//	return KSize(root->left, k - 1) + KSize(root->right, k - 1);
//}
//
//int maxDepth(struct TreeNode* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	int leftDepth = maxDepth(root->left);
//	int rightDepth = maxDepth(root->right);
//	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//	int depth = maxDepth(root);
//	*returnSize = depth;
//	int** arr = (int**)malloc(sizeof(int*) * depth);
//	*returnColumnSizes = (int*)malloc(sizeof(int) * depth);
//	for (int i = 0; i < depth; ++i) {
//		int n = KSize(root, i+1);
//		(*returnColumnSizes)[i] = 0;
//		arr[i] = (int*)malloc(sizeof(int) * n);
//	}
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, root);
//	int cnt1 = 1, cnt2 = 0;
//	for (int i = 0; i < depth; ++i) {
//		for (int j = 0; j < cnt1 && !QueueEmpty(&q); ++j) {
//			struct TreeNode* tmp = QueueHead(&q);
//			arr[i][j] = tmp->val;
//			(*returnColumnSizes)[i]++;
//			QueuePop(&q);
//			if (tmp->left) {
//				QueuePush(&q, tmp->left);
//				cnt2++;
//			}
//			if (tmp->right) {
//				QueuePush(&q, tmp->right);
//				cnt2++;
//			}
//		}
//		cnt1 = cnt2;
//		cnt2 = 0;
//	}
//	QueueDestroy(&q);
//	return arr;
//}
//
//
//
//int main() {
//	BTNode* root = CreateTree();
//	int ret = KSize(root, 2);
//	int** p = NULL;
//	int n = 0;
//	int* q = NULL;
//	p = levelOrder(root, &n, &q);
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < q[i]; ++j) {
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}