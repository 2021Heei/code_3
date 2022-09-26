#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void Swap(int* a, int* b);

void PrintSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//直接插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);


//向下调整
void AdjustDown(int* a, int size, int parent);
void HeapSort(int* a, int n);

