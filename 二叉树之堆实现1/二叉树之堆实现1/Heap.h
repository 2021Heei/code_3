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

//初始化堆
void HeapInit(Heap* php);

//销毁堆
void HeapDestroy(Heap* php);

//打印堆数据
void HeapPrint(Heap* php);

//交换
void Swap(HPDataType* a, HPDataType* b);

//向上调整，child是子节点下标
void AdjustUp(HPDataType* arr, int child);

//入数据到堆并保持堆结构
void HeapPush(Heap* php, HPDataType val);

//向下调整
void AdjustDown(HPDataType* arr, int size, int parent);

//删除堆顶元素并保持堆结构
void HeapPop(Heap* php);

//取到堆顶元素
HPDataType HeapTop(Heap* php);

//判断堆是否为空
bool HeapEmpty(Heap* php);

//返回堆的大小
int HeapSize(Heap* php);