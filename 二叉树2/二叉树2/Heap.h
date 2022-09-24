#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int HPDataType;
typedef struct Heap {
	HPDataType* pdata;
	int size;
	int capacity;
}Heap;

//���ϵ���
void AdjustUp(HPDataType* a, int child);

//���µ���
void AdjustDown(HPDataType* a, int size, int parent);

void Swap(HPDataType* pa, HPDataType* pb);

//�ѳ�ʼ��
void HeapInit(Heap* php);

//��ӡ�Ѵ�������
void HeapPrint(Heap* php);

//�ѵ�����
void HeapDestroy(Heap* php);

//�������ݵ��ѣ�������
void HeapPush(Heap* php, HPDataType val);

//ɾ���Ѷ�Ԫ��
void HeapPop(Heap* php);

//ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* php);

//�ѵĴ�С
int HeapSize(Heap* php);

//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(Heap* php);

//TopK����
//��N�������С�������������ģ���С�ģ�ǰK��
void PrintTopK(int* a, int n, int k);

void HeapSort(int* a, int n);


