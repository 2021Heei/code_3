#define _CRT_SECURE_NO_WARNINGS 1
//快速单链表构建-基本结构
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};


//找中间节点，返回结点地址
struct ListNode* ListSearchMid(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//逆置，返回逆置后的头结点地址
struct ListNode* ListReverse(struct ListNode* head) {
	struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
	guard->next = NULL;
	struct ListNode* cur = head;
	struct ListNode* later = NULL;


	while (cur) {
		later = cur->next;
		cur->next = guard->next;
		guard->next = cur;
		cur = later;
	}
	head = guard->next;
	free(guard);
	//guard = NULL;
	return head;
}

bool isPalindrome(struct ListNode* head) {
	struct ListNode* mid = ListSearchMid(head);
	struct ListNode* remid = ListReverse(mid);
	while (head && remid) {
		if (head->val != remid->val) {
			return false;
		}
		head = head->next;
		remid = remid->next;
	}
	return true;
}



int main() {
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n1);
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n2);
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n3);
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n4);
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n5);
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n6);
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n7);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	/*n5->next = n6;
	n6->next = n7;
	n7->next = NULL;*/

	n1->val = 1;
	n2->val = 2;
	n3->val = 2;
	n4->val = 1;
	/*n5->val = 4;
	n6->val = 5;
	n7->val = 6;*/
	
	int ret = isPalindrome(n1);
	

	return 0;
}
//
//#include<iostream>
//using namespace std;
//typedef int ElemType;
//typedef struct
//{
//	ElemType* data;
//	int size;
//	int length;
//} Sqlist;
//
//bool Initlist(Sqlist& L, int s = 100);                          //初始化顺序表
//int LIstLength(const Sqlist& L);                                //求线性长度
//int locate(const Sqlist& L, const ElemType e);                   //安值查找
//int GetData(const Sqlist& L, int i);                            //获得第i个元素
//bool InList(Sqlist& L, int i, const ElemType e);                //在第i个元素之前插入一个元素
//bool OutList(Sqlist& L, int i, const ElemType e);               //在第i个元素之后插入一个元素
//bool DelList(Sqlist& L, int i);                                 //删除第i个元素
//void DestroyList(Sqlist& L);                                    //销毁顺序表
//bool EmptyList(const Sqlist& L);                                //判断是否为空
//void Displist(const Sqlist& L);                                 //遍历顺序表
//void ClearList(Sqlist& L);                                       //清空顺序表
//bool put(Sqlist& L, int a, int b);                               //输入顺序表
//Sqlist scp(Sqlist& L, Sqlist& T);                                 //拼接顺序表
//Sqlist lscp(Sqlist& L, Sqlist& T);                                //拼接顺序表（需要较长的剩余空间）
//void maopao(int arr[], int len);                                //冒泡排序
//void chushi1(Sqlist& L);
//void chushi2(Sqlist& L);
//void chushi1(Sqlist& L) {
//	L.data = new ElemType[1000]{ 34, 12, 45, 23, 78, 34, 12, 34, 12, 78 };
//	L.size = 1000;
//	L.length = 10;
//}
//void chushi2(Sqlist& L) {
//	L.data = new ElemType[10]{ 23,13,25,16,57,35,432,29,10,13 };
//	L.size = 10;
//	L.length = 10;
//}
//bool Initlist(Sqlist& L, int s)
//{
//	if (s <= 0) s = 100;
//	L.data = new ElemType[s];                                   //开辟空间
//	if (L.data == NULL) return false;
//	L.size = s;
//	L.length = 0;                                               //初始长度为零
//}
//bool put(Sqlist& L, int size, int len) {
//	Initlist(L, size);
//	L.length = len;
//	ElemType a = 0;
//	if (len > size)return false;
//	for (int i = 0; i < len; i++) {
//		L.data[i] = a;                                           //可自行输入
//	}
//}
//int LIstLength(const Sqlist& L)
//{
//	return L.length;
//}
//int locate(const Sqlist& L, const ElemType e) {
//	for (int i = 0; i < L.length; i++)
//	{
//		if (L.data[i] == e)return i + 1;
//	}
//	return false;
//}
//int GetData(const Sqlist& L, int i)
//{
//	ElemType e;
//	if (i >= 1 && i <= L.length) {
//		e = L.data[i - 1];
//		return e;
//	}
//
//}
//bool InList(Sqlist& L, int i, const ElemType e) {
//	if (i<1 || i>L.length + 1) return false;
//	if (L.length == L.size) {                               //空间不够开辟两倍空间
//		ElemType* temp = new ElemType[2 * L.size];
//		if (temp == NULL) return false;
//		for (int i = 0; i < L.length; i++)
//			temp[i] = L.data[i];
//		delete[]L.data;
//		L.data = temp;
//		L.size = L.size * 2;
//	}
//	for (int k = L.length - 1; k >= i - 1; k--)            //前插法
//		L.data[k + 1] = L.data[k];
//	L.data[i - 1] = e;
//	L.length++;
//	return true;
//	cout << L.length << "Inlist";
//
//
//}
//bool OutList(Sqlist& L, int i, const ElemType e) {
//	if (i<1 || i>L.length + 1) return false;
//	if (L.length == L.size) {
//		ElemType* temp = new ElemType[2 * L.size];
//		if (temp == NULL) return false;
//		for (int i = 0; i < L.length; i++)
//			temp[i] = L.data[i];
//		delete[]L.data;
//		L.data = temp;
//		L.size = L.size * 2;
//	}
//	for (int k = L.length - 1; k >= i; k--)                //尾插法
//		L.data[k + 1] = L.data[k];
//	L.data[i] = e;
//	L.length++;
//	return true;
//	cout << L.length << "Outlist";
//}
//
//bool DelList(Sqlist& L, int i) {
//	if (i >= 1 && i <= L.length) {
//		for (int k = i; k < L.length; k++)
//			L.data[k - 1] = L.data[k];
//		L.length--;
//		return true;
//	}
//	return false;
//}
//
//void DestroyList(Sqlist& L)
//{
//	delete[] L.data;
//	L.data = NULL;
//	L.size = 0;
//	L.length = 0;
//}
//void ClearList(Sqlist& L)
//{
//	L.length = 0;
//}
//bool EmptyList(const Sqlist& L)
//{
//	if (L.length == 0)
//		return true;
//	else return false;
//}
//void Displist(Sqlist& L)
//{
//	for (int i = 0; i < L.length; i++) {
//		cout << L.data[i] << " ";
//	}
//
//}
//
//Sqlist scp(Sqlist& L, Sqlist& T) {
//	Sqlist t;
//	int i = 0, j = 0;
//	t.length = L.length + T.length;
//	t.size = L.size + T.size;
//	t.data = new ElemType[t.size];
//	for (i = 0; i < L.length; i++) {
//		t.data[i] = L.data[i];
//	}
//	for (i = L.length; i < t.length; i++) {
//		t.data[i] = T.data[j++];
//	}
//	maopao(t.data, t.length);
//	return t;
//}
//
//Sqlist lscp(Sqlist& L, Sqlist& T) {
//	int i = 0;
//	int newlen = L.length + T.length;
//	for (i = 0; i < T.length; i++) {
//		L.data[L.length++] = T.data[i];
//	}
//	maopao(L.data, newlen);
//	return L;
//}
//void maopao(ElemType arr[], int len) {
//	int i, j;
//	for (i = 0; i < len - 1; i++)
//		for (j = 0; j < len - 1 - i; j++)
//			if (arr[j] > arr[j + 1])
//				swap(arr[j], arr[j + 1]);
//
//}
//int main()
//{
//	Sqlist L;
//	Sqlist T;
//	chushi1(L);
//	chushi2(T);
//	Sqlist m = scp(L, T);
//	Sqlist n = lscp(L, T);
//	Displist(m);
//	cout << endl;
//	Displist(n);
//
//
//
//
//	return 0;
//}


//#include <stdio.h>
//
//#define LA 100
//#define Lb 100
//
//void  Sort(int* nums1, int nums1Size, int* nums2, int nums2Size);
//int main() {
//	int la[LA] = { 3,5,8,11 };
//	int lb[Lb] = { 2,6,8,9,11,15,20 };
//	int m = 11, j, k;
//
//	Sort(la, 4, lb, 7);
//
//	for (int i = 0; i <= m-1; ++i) {
//		printf("%d ", la[i]);
//	}
//	return 0;
//}
//
//
//void  Sort(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//	int old1 = nums1Size - 1;
//	int old2 = nums2Size - 1;
//	int n = nums1Size + nums2Size - 1;
//	while (old1 >= 0 && old2 >= 0) {
//		if (nums1[old1] > nums2[old2]) {
//			nums1[n] = nums1[old1];
//			--n;
//			--old1;
//		}
//		else {
//			nums1[n] = nums2[old2];
//			--n;
//			--old2;
//		}
//	}
//
//	if (old2 >= 0) {
//		while (old2 >= 0) {
//			nums1[n--] = nums2[old2--];
//		}
//	}
//}