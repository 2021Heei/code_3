//��������
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��̬˳���
#define SIZE_INIT 2			//��ʼ����Ĵ�С
#define CAPACITY_INIT 2		//��ʼ������
#define MULTIPLE 2			//���ݵı���
typedef int SLDataType;

typedef struct SeqList {
	SLDataType *data;//
	int size;//��ǰ��Ĵ�С
	int capacity;//�������
}SL;

//��ʼ��
void SLInit(SL* psl);

//����˳���
void SLDestory(SL* psl);

//��ӡ˳���
void SLPrint(const SL* psl);

//�������������
void SLCheckCapacity(SL* psl);

//β��βɾ ͷ��ͷɾ
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);


//����,�ҵ������±꣬���򷵻�-1
int FindSL(const SL* psl, SLDataType x);

//��posλ�ò���x
void SLInsert(SL* psl, size_t pos, SLDataType x);

//ɾ��posλ�õ�ֵ
void SLErase(SL* psl, size_t pos);

//�޸�posλ�õ�ֵ
void SLModify(SL* psl, size_t pos);
#endif
