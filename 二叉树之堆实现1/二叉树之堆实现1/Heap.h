#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdBool.h>

//typedef int HPDataType;
//typedef struct HeapNode {
//	HPDataType* data;
//	int size;
//	int capacity;
//}HeapNode;

typedef int HPDataType;
typedef struct{
	HPDataType* pdata;
	int size;
	int capacity;
}Heap;

//��ʼ����
void HeapInit(Heap* php);

//���ٶ�
void HeapDestroy(Heap* php);

//��ӡ������
void HeapPrint(Heap* php);

//����
void Swap(HPDataType* a, HPDataType* b);

//���ϵ�����child���ӽڵ��±�
void AdjustUp(HPDataType* arr, int child);

//�����ݵ��Ѳ����ֶѽṹ
void HeapPush(Heap* php, HPDataType val);

//���µ���
void AdjustDown(HPDataType* arr, int size, int parent);

//ɾ���Ѷ�Ԫ�ز����ֶѽṹ
void HeapPop(Heap* php);

//ȡ���Ѷ�Ԫ��
HPDataType HeapTop(Heap* php);

//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(Heap* php);

//���ضѵĴ�С
int HeapSize(Heap* php);