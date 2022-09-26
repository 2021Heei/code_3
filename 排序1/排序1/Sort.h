#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void Swap(int* a, int* b);

void PrintSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//ֱ�Ӳ�������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);


//���µ���
void AdjustDown(int* a, int size, int parent);
void HeapSort(int* a, int n);

