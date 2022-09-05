#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define INITCAPACITY 1000//����
typedef int SLDataType;

typedef struct SeqList {
	SLDataType data[INITCAPACITY];
	int size;//��̬˳����С
}SL;

//��ʼ��˳���
void SLInit(SL* phead);

//���˳���
void SLPrint(const SL* phead);

//����˳���
void SLDestroy(SL* phead);


//ͷ��β�� ͷɾβɾ
void SLPushBack(SL* phead, SLDataType x);
void SLPushFront(SL* phead, SLDataType x);
void SLPopBack(SL* phead);
void SLPopFront(SL* phead);

//����posλ��Ԫ��,�ҵ��ͷ����±꣬���򷵻�-1
int SLFind(const SL* phead, SLDataType x);

//�޸�posλ��Ԫ��
void SLModify(SL* phead, size_t pos, SLDataType x);

//��posλ��ǰ����һ������Ԫ��
void SLInsert(SL* phead, size_t pos, SLDataType x);

//ɾ��posλ�õ�����
void SLErase(SL* phead, size_t pos);

//ʹ�ýӿ�SLInsert()��SLErase()��ͷ��β�塢ͷɾβɾ
void SLPushBack2(SL* phead, SLDataType x);
void SLPushFront2(SL* phead, SLDataType x);
void SLPopBack2(SL* phead);
void SLPopFront2(SL* phead);