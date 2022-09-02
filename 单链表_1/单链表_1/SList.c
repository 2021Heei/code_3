#include "SList.h"

//���
void SListPrint(SLTNode* phead) {
	//ͷָ��ָ�������һ��Ԫ�ػ���ָ��NULL������Ҫ�ж�ͷָ���Ƿ�Ϊ��
	SLTNode* cur = phead;
	while (cur) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//����
void SListDestroy(SLTNode** pphead) {
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur->next != NULL) {
		SLTNode* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
}

//����һ���½ڵ�
SLTNode* BuySLTNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode) {
		perror("BuySLTNode:");
	}
	newnode->data = x;
	newnode->next = NULL;
}

//ͷ��β�� ͷɾβɾ
void SListPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

void SListPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);

	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		//tail β��
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

void SListPopFront(SLTNode** pphead) {
	assert(pphead);
	//�жϵ������Ƿ�Ϊ�գ���Ϊ�վͱ�������
	assert(*pphead);
	////��������
	//if (*pphead == NULL) {
	//	return;
	//}

	SLTNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}

void SListPopBack(SLTNode** pphead) {
	assert(pphead);
	//�жϵ������Ƿ�Ϊ�գ���Ϊ�վͱ�������
	assert(*pphead);
	////��������
	//if (*pphead == NULL) {
	//	return;
	//}

	if ((*pphead)->next == NULL) {
		//ֻ��һ�����
		*pphead = NULL;
	}
	else {
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;

		/*SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/

	}

}

//���ң����ı䴫���ͷָ��plist�����Բ�ʹ�ö���ָ��
SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	SLTNode* cur = phead;
	while (cur->next) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//��pos�ڵ�ǰ����һ���½ڵ�,ֻ��һ�����ʱ��Ҫ�ı�ͷָ��plist������Ҫ����ָ��
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead);
	assert(pos);
	if (*pphead == pos) {
		SListPushFront(pphead, x);
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos) {
		
		prev = prev->next;
	}

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = prev->next;
	prev->next = newnode;
}

//��pos�ڵ�����һ���½ڵ�
//���ڴ�����ǽ���ַ�����ܵ��ǽṹ��ָ�룬ָ���˽��
void SListInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��pos�ڵ�
void SListErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead);
	assert(pos);
	//��ɾ��������һ�����
	SLTNode* prev = *pphead;
	while (prev->next != pos) {
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}

//ɾ��pos���ĺ�һ�����
void SListEraseAfter(SLTNode* pos) {
	assert(pos);
	if (pos->next == NULL) {
		return;
	}
	else {
		SLTNode* tmp = pos->next;
		pos->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}