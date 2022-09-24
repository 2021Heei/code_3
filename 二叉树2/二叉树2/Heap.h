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

//向上调整
void AdjustUp(HPDataType* a, int child);

//向下调整
void AdjustDown(HPDataType* a, int size, int parent);

void Swap(HPDataType* pa, HPDataType* pb);

//堆初始化
void HeapInit(Heap* php);

//打印堆储存数据
void HeapPrint(Heap* php);

//堆的销毁
void HeapDestroy(Heap* php);

//输入数据到堆，并建堆
void HeapPush(Heap* php, HPDataType val);

//删除堆顶元素
void HeapPop(Heap* php);

//取堆顶元素
HPDataType HeapTop(Heap* php);

//堆的大小
int HeapSize(Heap* php);

//判断堆是否为空
bool HeapEmpty(Heap* php);

//TopK问题
//在N个最大（最小）的里面找最大的（最小的）前K个
void PrintTopK(int* a, int n, int k);

void HeapSort(int* a, int n);


