#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
*	��ͷ���ĵ�����
*	�����ӿ����Ϊ����ͷ���ĵ�ַ
*	ʵ��˼·����main�����ڲ�����ֲ�ͷ���ָ�������ͷ�����һ����ʼ�������궯̬���룬�ɹ��ͷ���ͷ����ַ��ʧ�ܷ���NULL��ÿ�δ��뺯���ӿڵ��Ǿֲ��ڵ�ָ�����
*	���ܣ�ͷ�巨��β�巨����������
*		  ������Ԫ������
*		  �ڵ������в���Ԫ�أ��ҵ��ͷ��ؽڵ�ָ�룬���򷵻�NULL
*		  ɾ���ڵ�Ԫ��
*		  �õ�������
*		  ���ٵ�����
*
*/

//��ͷ˫��ѭ������
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DLTDataType;
typedef struct DListNode {
	DLTDataType data;
	struct DListNode* next;
	struct DListNdoe* prev;
}DLTNode;

//��ʼ��
DLTNode* DListInit();

//���������������
void DListPrint(DLTNode* phead);

//��������,һ��ָ����߶���ָ�붼����,ֻ����һ��ָ����ͷָ����Ҫ���ⲿ���ÿ�
void DListDestroy(DLTNode* phead);

//ͷ��β�� ͷɾβɾ
void DListPushBack(DLTNode* phead, DLTDataType x);
void DListPushFront(DLTNode* phead, DLTDataType x);
void DListPopBack(DLTNode* phead);
void DListPopFront(DLTNode* phead);

//�������ݲ����ؽڵ��ַ
DLTNode* DListFind(DLTNode* phead, DLTDataType x);

//��pos�ڵ����һ���ڵ�
void DListInsert(DLTNode* pos, DLTDataType x);

//ɾ��pos�ڵ�
void DListErase(DLTNode* pos);

//˫������ĳ���
int DListLength(DLTNode* phead);

//����Ԫ������ - ��С����
void SListSort(DLTNode* pguard);