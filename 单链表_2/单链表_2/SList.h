//#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
////������󲿷�ͨ������ָ��ʵ�ֵ��򡢲�ѭ������ͷ�ڵ�(���ڱ�ͷ)������
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//
//typedef int SLTDataType;
////�ڵ�����
//typedef struct SListNode {
//	SLTDataType data;
//	struct SListNode* next;
//}SLNode;
//
//
////�������������̨
//void SListPrint(SLNode* phead);
//
////���ٵ�����
//void SListDestroy(SLNode** pphead);
//
////����һ���½ڵ�
//SLNode* BuyNode(SLTDataType x);
//
////ͷ��β�� ͷɾβɾ
//void SListPushBack(SLNode** pphead, SLTDataType x);
//void SListPushFront(SLNode** pphead, SLTDataType x);
//void SListPopBack(SLNode** pphead);
//void SListPopFront(SLNode** pphead);
//
////�������ݣ��ҵ��������ڽڵ�ĵ�ַ
//SLNode* SListFind(SLNode* phead, SLTDataType x);
//
////��pos�ڵ�֮ǰ��������
//void SListInsert(SLNode** pphead, SLNode* pos, SLTDataType x);
//
////��pos�ڵ�֮���������
//void SListInsertAfter(SLNode* pos, SLTDataType x);
//
////ɾ��pos�ڵ�
//void SListErase(SLNode** pphead, SLNode* pos);
//
////ɾ��pos�ڵ�֮��Ľڵ�
//void SListEraseAfter(SLNode* pos);