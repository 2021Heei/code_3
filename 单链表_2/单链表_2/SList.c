#include "SList.h"

//�������������̨
void SListPrint(SLNode* phead) {
	while (phead) {
		printf("%d ", phead->data);
		phead = phead->next;
	}
	printf("\n");
}

//���ٵ�����
void SListDestroy(SLNode** pphead) {
	assert(pphead);
	SLNode* cur = *pphead;
	while (cur) {
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

SLNode* BuyNode(SLTDataType x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (!newnode) {
		perror("newnode\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
}

//ͷ��β�� ͷɾβɾ
void SListPushBack(SLNode** pphead, SLTDataType x) {
	assert(pphead);
	SLNode* newnode = BuyNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		SLNode* cur = *pphead;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SListPushFront(SLNode** pphead, SLTDataType x) {
	assert(pphead);
	SLNode* newnode = BuyNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

void SListPopBack(SLNode** pphead) {
	assert(pphead);
	assert(*pphead);//Ϊ��ʱ����ɾ��
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		////��1
		//SLNode* cur = *pphead;
		//while (cur->next->next) {
		//	cur = cur->next;
		//}
		//free(cur->next);
		//cur->next = NULL;

		//��2
		SLNode* prev = NULL;
		SLNode* cur = *pphead;
		while (cur->next) {
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		//cur = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SLNode** pphead) {
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLNode* cur = *pphead;
		*pphead = cur->next;
		free(cur);
		//cur == NULL;
	}
}

//�������ݣ��ҵ��������ڽڵ�ĵ�ַ
SLNode* SListFind(SLNode* phead, SLTDataType x) {
	SLNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��pos�ڵ�֮ǰ��������
void SListInsert(SLNode** pphead, SLNode* pos, SLTDataType x) {
	assert(pphead);
	assert(*pphead);//������Ϊ�ղ鲻����ǿ������
	////��������
	//if (*pphead == NULL) {
	//	return;
	//}
	////��1�����������ҵ�posǰһ���ٲ���
	//if ((*pphead) == pos) {
	//	SLNode* newnode = BuyNode(x);
	//	newnode->next = *pphead;
	//	*pphead = newnode;
	//}
	//else {
	//	SLNode* prev = *pphead;
	//	//��posǰһ��λ��
	//	while (prev->next != pos) {
	//		prev = prev->next;
	//		//���prevΪNULL��˵������������Ҳû�ҵ�pos�����δ��󣬱������
	//		assert(prev);
	//	}
	//	SLNode* newnode = BuyNode(x);
	//	newnode->next = pos;
	//	prev->next = newnode;
	//}

	//��2����è��̫�ӣ����뵽pos���棬�ڽ��������ڵ��ֵ
	//���ַ������漰ͷָ�룬������ı�ͷָ���ֵ����ȷ�1�����˶�ͷָ�������ʹ��
	SLNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	int tmp = pos->data;
	pos->data = newnode->data;
	newnode->data = tmp;
}


//��pos�ڵ�֮���������
void SListInsertAfter(SLNode* pos, SLTDataType x) {
	SLNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��pos�ڵ�
void SListErase(SLNode** pphead, SLNode* pos) {
	assert(pphead);
	if (*pphead == pos) {
		//ͷ������
		SListPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
			assert(prev);//prevΪNULLʱ˵�������������ˣ���û���ҵ�pos��˵��pos������
		}
		SLNode* tmp = pos;
		prev -> next = pos->next;
		//free(tmp);
		//tmp = NULL;�Ѿֲ�����tmp��ΪNULL������������pos���κ�Ӱ�죬������Ӧ���Լ��ֶ���NULL
	}
}
//ɾ��pos�ڵ�֮��Ľڵ�
void SListEraseAfter(SLNode* pos) {
	//pos��Ϊ��
	assert(pos);
	//pos->nextҲ��Ϊ��
	assert(pos->next);
	SLNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
	//�Ѿֲ�����tmp��ΪNULL������������pos���κ�Ӱ�죬������Ӧ���Լ��ֶ���NULL
	//tmp = NULL;
}