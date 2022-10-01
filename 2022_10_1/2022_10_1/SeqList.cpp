#include "SeqList.h"

//��ʼ��
void SLInit(SL* psl) {
	assert(psl);
	psl->data = (SLDataType*)malloc(sizeof(SLDataType) * SIZE_INIT);
	psl->size = 0;
	psl->capacity = CAPACITY_INIT;
}

//��ӡ˳���
void SLPrint(const SL* psl) {
	assert(psl);
	for (int i = 0; i < psl->size; ++i) {
		printf("%d ", psl->data[i]);
	}
	printf("\n");
}

//����˳���
void SLDestroy(SL* psl) {
	assert(psl);
	free(psl->data);
	psl->data = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//�������������
void SLCheckCapacity(SL* psl) {
	assert(psl);
	if (psl->size == psl->capacity) {
		SLDataType newcapacity = psl->capacity * MULTIPLE;
		SLDataType* tmp = (SLDataType*)realloc(psl->data, sizeof(SLDataType) * newcapacity);

		if (tmp == NULL) {
			perror("SLPushBack");
		}
		psl->data = tmp;
		psl->capacity = newcapacity;
	}
}

//ͷ��β��
void SLPushBack(SL * psl, SLDataType x) {
	//assert(psl);
	/*SLCheckCapacity(psl);
	psl->data[psl->size] = x;
	++psl->size;*/

	SLInsert(psl, psl->size, x);

}

void SLPushFront(SL* psl, SLDataType x) {
	//assert(psl);
	/*SLCheckCapacity(psl);

	for (int i = psl->size; i > 0; --i) {
		psl->data[i] = psl->data[i - 1];
	}

	psl->data[0] = x;
	++psl->size;*/
	SLInsert(psl, 0, x);
}


//ͷɾβɾ
void SLPopBack(SL* psl) {
	//assert(psl);
	//////�����ǰ����Ԫ�ز�����0�ͱ���
	////assert(psl->size > 0);
	////������psl->size
	//if (psl->size == 0) {
	//	return;
	//}
	//--psl->size;

	SLErase(psl, psl->size - 1);

}

void SLPopFront(SL* psl) {
	//assert(psl);
	//assert(psl->size > 0);
	//������psl->size
	/*if (psl->size == 0) {
		return;
	}
	for (int i = 0; i < psl->size - 1; ++i) {
		psl->data[i] = psl->data[i + 1];
	}
	--psl->size;*/
	SLErase(psl, 0);
}

//����,�ҵ������±꣬���򷵻�-1
int FindSL(const SL* psl, SLDataType x) {
	assert(psl);
	for (int i = 0; i < psl->size; ++i) {
		if (psl->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//��posλ�ò���x
void SLInsert(SL* psl, size_t pos, SLDataType x) {
	assert(psl);
	assert(pos <= psl->size);

	SLCheckCapacity(psl);
	for (size_t i = psl->size; i > pos; --i) {
		psl->data[i] = psl->data[i - 1];
	}
	psl->data[pos] = x;
	++psl->size;
}

//ɾ��posλ�õ�ֵ
void SLErase(SL* psl, size_t pos) {
	assert(psl);
	assert(pos < psl->size);
	//������Ԫ�ز�Ϊ�գ��������
	//assert(psl->size > 0);
	//////������
	////if (psl->size == 0) {
	////	return;
	////}
	int begin = pos;
	while (begin < psl->size - 1) {
		psl->data[begin] = psl->data[begin+1];
		++begin;
	}
	--psl->size;
}

//�޸�posλ�õ�ֵ
void SLModify(SL* psl, size_t pos, SLDataType x) {
	assert(psl);
	assert(pos < psl->size);
	psl->data[pos] = x;
}

//
size_t SLSize(SL* psl) {
	assert(psl);
	return psl->size;
}

//����posλ�õ�Ԫ�ص�����
SLDataType& SLAt(SL* psl, size_t pos) {
	assert(psl);
	assert(pos < psl->size);
	return psl->data[pos];
}