#ifndef __SEQLIST__H__
#define __SEQLIST__H__
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

//��װ˳���ṹ������
typedef struct SeqList{
	SLDataType *data;
	int size;
	int capacity;
}SL;

//��ʼ��
void SLInit(SL* psl);

//��ӡ
void SLPrint(const SL* psl);

//����
void SLDestroy(SL* psl);

//�������������
void SLCheckCapacity(SL* psl);

//ͷ��β�� ͷɾβɾ
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

//���ң��ҵ������±꣬���򷵻�-1
int SLFind(SL* psl, size_t pos);

//ָ��posλ�ò�������x
void SLInsert(SL* psl, size_t pos, SLDataType x);

//ָ��posλ��ɾ������x
void SLErase(SL* psl, size_t pos);

//ָ��posλ�ò��޸�����
void SLModify(SL* psl, size_t pos, SLDataType x);

#endif
