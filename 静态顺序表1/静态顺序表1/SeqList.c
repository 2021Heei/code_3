#include "SeqList.h"

//��ʼ��˳���
void SLInit(SL* phead) {
	assert(phead);
	memset(phead, 0, sizeof(SL));
}

//���˳���
void SLPrint(const SL* phead) {
	assert(phead);
	for (int i = 0; i < phead->size; ++i) {
		printf("%d ", phead->data[i]);
	}
	printf("\n");
}

//����˳���
void SLDestroy(SL* phead) {
	assert(phead);
	phead->size = 0;
	memset(phead, 0, sizeof(SL));
}

//ͷ��β�� ͷɾβɾ
void SLPushBack(SL* phead, SLDataType x) {
	assert(phead);
	//������飬��˳����Ѿ���ʱ�������������ݵĲ����ᵼ�±���
	assert(phead->size < INITCAPACITY);
	phead->data[phead->size] = x;
	++phead->size;

}

void SLPushFront(SL* phead, SLDataType x) {
	assert(phead);
	//������飬��˳����Ѿ���ʱ�������������ݵĲ����ᵼ�±���
	assert(phead->size < INITCAPACITY);
	for (int i = phead->size; i > 0; --i) {
		phead->data[i] = phead->data[i - 1];
	}
	phead->data[0] = x;
	phead->size++;
}

void SLPopBack(SL* phead) {
	assert(phead);
	//������飬��˳����Ѿ�Ϊ��ʱ���ڳ��Խ���ɾ���������ᱨ��
	assert(phead->size > 0);
	--phead->size;
}

void SLPopFront(SL* phead) {
	assert(phead);
	//������飬��˳����Ѿ�Ϊ��ʱ���ڳ��Խ���ɾ���������ᱨ��
	assert(phead->size > 0);
	for (int i = 0; i < phead->size - 1; ++i) {
		phead->data[i] = phead->data[i + 1];
	}
	--phead->size;
}


//����Ԫ��,�ҵ��ͷ����±꣬���򷵻�-1
int SLFind(const SL* phead, SLDataType x) {
	assert(phead);
	for (int i = 0; i < phead->size; ++i) {
		if (phead->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//�޸�posλ��Ԫ��
void SLModify(SL* phead, size_t pos, SLDataType x) {
	assert(phead);
	//������飬��������±�Խ��ʱ�ͱ���
	assert(pos < phead->size);
	phead->data[pos] = x;
}

//��posλ��ǰ����һ������Ԫ��
void SLInsert(SL* phead, size_t pos, SLDataType x) {
	assert(phead);
	//������飬��������±�Խ��ʱ�ͱ���
	assert(pos <= phead->size && phead->size < INITCAPACITY);
	for (int i = phead->size; i > pos; --i) {
		phead->data[i] = phead->data[i - 1];
	}
	phead->data[pos] = x;
	++phead->size;
}

//ɾ��posλ�õ�����
void SLErase(SL* phead, size_t pos) {
	assert(phead);
	for (int i = pos; i < phead->size - 1; ++i) {
		phead->data[i] = phead->data[i + 1];
	}
	--phead->size;
}

//ʹ�ýӿ�SLInsert()��SLErase()��ͷ��β�塢ͷɾβɾ

void SLPushBack2(SL* phead, SLDataType x) {
	SLInsert(phead, phead->size, x);
}

void SLPushFront2(SL* phead, SLDataType x) {
	SLInsert(phead, 0, x);
}

void SLPopBack2(SL* phead) {
	SLErase(phead, phead->size - 1);
}

void SLPopFront2(SL* phead) {
	SLErase(phead, 0);
}