#include "SList.h"

//输出
void SListPrint(SLTNode* phead) {
	//头指针指向单链表第一个元素或者指向NULL，不需要判断头指针是否为空
	SLTNode* cur = phead;
	while (cur) {
		printf("%c->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//销毁
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

//创建一个新节点
SLTNode* BuySLTNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode) {
		perror("BuySLTNode:");
	}
	newnode->data = x;
	newnode->next = NULL;
}

//头插尾插 头删尾删
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
		//tail 尾部
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

void SListPopFront(SLTNode** pphead) {
	assert(pphead);
	//判断单链表是否为空，若为空就报错提醒
	assert(*pphead);
	////温柔提醒
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
	//判断单链表是否为空，若为空就报错提醒
	assert(*pphead);
	////温柔提醒
	//if (*pphead == NULL) {
	//	return;
	//}

	if ((*pphead)->next == NULL) {
		//只有一个结点
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

//查找，不改变传入的头指针plist，可以不使用二级指针
SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	SLTNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//在pos节点前插入一个新节点,只有一个结点时需要改变头指针plist，故需要二级指针
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

//在pos节点后插入一个新节点
//关于传入的是结点地址，接受的是结构体指针，指向了结点
void SListInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos节点
void SListErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead);
	assert(pos);
    if(*pphead == pos){
        SListPopFront(pphead);
    }
    else{
    //待删除结点的上一个结点
	SLTNode* prev = *pphead;
	while (prev->next != pos) {
		prev = prev->next;
        assert(prev);
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
    }
}

//删除pos结点的后一个结点
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

SLTNode* ListIntersection(SLTNode* str1, SLTNode* str2) {
	SLTNode* cur1 = str1;
	SLTNode* cur2 = str2;
	int len1 = 0;
	int len2 = 0;
	//计算链表1的长度
	while (cur1) {
		++len1;
		cur1 = cur1->next;
	}
	//计算链表2的长度
	while (cur2) {
		++len2;
		cur2 = cur2->next;
	}
	//计算差距步
	int gap = abs(len1 - len2);
	SLTNode* LongList = str1;
	SLTNode* ShortList = str2;
	if (len1 < len2) {
		LongList = str2;
		ShortList = str1;
	}
	//长的先走差距步
	while (gap--) {
		LongList = LongList->next;
	}
	//一起走
	while (LongList/* && ShortList*/) {
		//相交是存在相等的节点地址
		if (LongList == ShortList) {
			return LongList;
		}
		LongList = LongList->next;
		ShortList = ShortList->next;
	}
	return NULL;
}