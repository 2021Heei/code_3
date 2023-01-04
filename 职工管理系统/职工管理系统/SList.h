#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SList* next;
}SLTNode;

//���
void SListPrint(SLTNode* phead);

//����
void SListDestroy(SLTNode** pphead);

//ͷ��β�� ͷɾβɾ
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);

//���ң����ı䴫���ͷָ��plist�����Բ�ʹ�ö���ָ��
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//��pos�ڵ�ǰ����һ���½ڵ�,ֻ��һ�����ʱ��Ҫ�ı�ͷָ��plist������Ҫ����ָ��
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//��pos�ڵ�����һ���½ڵ�
//���ڴ�����ǽ���ַ�����ܵ��ǽṹ��ָ�룬ָ���˽��
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//ɾ��pos�ڵ�
void SListErase(SLTNode** pphead, SLTNode* pos);

//ɾ��pos���ĺ�һ�����
void SListEraseAfter(SLTNode* pos);

//�޸�pos�ڵ������

