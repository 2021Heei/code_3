#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
*	��ͷ���ĵ�����
*	�����ӿ����Ϊ����ͷ���ĵ�ַ
*	ʵ��˼·����main�����ڲ�����ֲ�ͷ��������ÿ��ȡ�ֲ�ͷ��������ַ���뺯���ӿ�
*	���ܣ�ͷ�巨��β�巨����������
*		  ������Ԫ������
*		  �ڵ������в���Ԫ�أ��ҵ��ͷ��ؽڵ�ָ�룬���򷵻�NULL
*		  ɾ���ڵ�Ԫ��
*		  �õ�������
*		  ���ٵ�����
*		  
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLTDataType;
//�ڵ�����
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLNode;

//��ʼ���ڱ�ͷ���
void SListInit(SLNode* pguard);

//�������������̨
void SListPrint(SLNode* pguard);

//���ٵ�����
void SListDestroy(SLNode* pguard);

//����һ���½ڵ�
SLNode* BuyNode(SLTDataType x);

//ͷ��β�� ͷɾβɾ
void SListPushBack(SLNode* pguard, SLTDataType x);
void SListPushFront(SLNode* pguard, SLTDataType x);
void SListPopBack(SLNode* pguard);
void SListPopFront(SLNode* pguard);

//�������ݣ��ҵ��������ڽڵ�ĵ�ַ
SLNode* SListFind(SLNode* pguard, SLTDataType x);

//ɾ��pos�ڵ�
void SListErase(SLNode* pguard, SLNode* pos);

//������
int SListLength(SLNode* pguard);

//�������� - ��С����
void SListSort(SLNode* pguard);