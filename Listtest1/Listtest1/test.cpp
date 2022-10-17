#define _CRT_SECURE_NO_WARNINGS 1
////快速单链表构建-基本结构
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
////struct ListNode* rotateRight(struct ListNode* head, int k) {
////	int len = 0;
////	struct ListNode* cur = head;
////	while (cur) {
////		cur = cur->next;
////		++len;
////	}
////	k %= len;
////	while (len--) {
////		//找尾
////		cur = head;
////		struct ListNode* prev = NULL;
////		while (cur->next) {
////			prev = cur;
////			cur = cur->next;
////		}
////		prev->next = NULL;
////		cur->next = head;
////		head = cur;
////	}
////	return head;
////}
//
//
//struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
//    if (left == right) {
//        return head;
//    }
//    struct ListNode* myhead = head;
//    struct ListNode* mytail = head;
//    struct ListNode* midhead = head;
//    struct ListNode* midtail = head;
//    struct ListNode* cur = head;
//    int cnt = 0;
//    while (cur) {
//        cnt++;
//        if (cnt == left) {
//            midhead = cur;
//        }
//        if (cnt == right) {
//            midtail = cur;
//        }
//        cur = cur->next;
//    }
//    mytail = midtail->next;
//    cur = midhead;
//    struct ListNode* prev = mytail;
//    struct ListNode* next = NULL;
//    while (cur != mytail) {
//        next = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = next;
//    }
//    myhead->next = prev;
//    
//    return myhead;
//}
//
//int main() {
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n5);
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//	n5->val = 5;
//
//    n1->val = 3;
//    n2->val = 5;
//    n1->next = n2;
//    n2->next = NULL;
//
//    n1 = reverseBetween(n1, 1, 2);
//    //n1 = reverseBetween(n1, 2, 4);
//    while (n1) {
//        printf("%d->", n1->val);
//        n1 = n1->next;
//    }
//    printf("nullptr");
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int solution(int n, int m, int arr1[]) {
//    int result = 0;
//    for (int i = 1; i <= n; ++i) {
//
//        for (int j = 0; j < m; ++j) {
//            if (i % arr1[j] == 0) {
//                result++;
//                break;
//            }
//        }
//    }
//
//    // TODO: 请在此编写代码
//
//    return n - result;
//}
//
//
//int main() {
//
//    int n;
//    int m;
//    scanf("%d", &n);
//    scanf("%d", &m);
//
//
//    int* arr1;
//    arr1 = (int*)malloc(m * sizeof(int));
//
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//
//
//    int result = solution(n, m, arr1);
//
//    printf("%d", result);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int* solution(int m, int arr1[], int* return_size) {
//    //return_size: result长度
//    *return_size = m;
//    int* result = (int*)malloc(sizeof(int) * m);
//    int cnt1 = 0, cnt2 = 0;
//    for (int i = 0; i < m; ++i) {
//        if (arr1[i] % 2 == 0) {
//            cnt2++;
//        }
//        else {
//            cnt1++;
//        }
//    }
//    int* a1 = (int*)malloc(sizeof(int) * cnt1);
//    int* a2 = (int*)malloc(sizeof(int) * cnt2);
//    int x1 = 0;
//    int x2 = 0;
//    for (int i = 0; i < m; ++i) {
//        if (arr1[i] % 2 == 0) {
//            a2[x2++] = arr1[i];
//        }
//        else {
//            a1[x1++] = arr1[i];
//        }
//    }
//    int i = 0;
//    for (; i < cnt1; ++i) {
//        result[i] = a1[i];
//    }
//    for (int j = 0; j < cnt2; ++j) {
//        result[i++] = a1[j];
//    }
//    // TODO: 请在此编写代码
//
//    return result;
//}
//
//
//int main() {
//
//    int n;
//    scanf("%d", &n);
//
//
//    int* arr;
//    arr = (int*)malloc(n * sizeof(int));
//
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    int return_size;
//    int* result = solution(n, arr, &return_size);
//
//    for (int i = 0; i < return_size; i++) {
//        printf("%d ", result[i]);
//    }
//
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* solution(int m, int arr1[], int* return_size) {
    //return_size: result长度
    int* result = arr1;

    // TODO: 请在此编写代码
    int left = 0;
    int right = m - 1;
    *return_size = m;
    while (left < right) {
        //找偶数
        while (result[left] % 2 != 0) {
            left++;
        }
        //找奇数
        while (result[right] % 2 == 0) {
            right--;
        }
        if (left < right) {
            int tmp = result[left];
            result[left] = result[right];
            result[right] = tmp;
        }
    }
    return result;
}

//6
//3 34 67 89 90 58
//int main() {
//
//    int n;
//    scanf("%d", &n);
//
//
//    int* arr;
//    arr = (int*)malloc(n * sizeof(int));
//
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    int return_size;
//    int* result = solution(n, arr, &return_size);
//
//    for (int i = 0; i < return_size; i++) {
//        printf("%d ", result[i]);
//    }
//
//    return 0;
//}


char* addSpaces(char* s, int* spaces, int spacesSize) {
    int len = strlen(s);
    char* str = (char*)malloc(sizeof(char) * (len + spacesSize + 1));
    memset(str, 0, sizeof(len + 1 + spacesSize));
    strcpy(str, s);
    for (int i = spacesSize - 1; i >= 0; --i) {

        //移位
        for (int j = len + spacesSize - 1; j > spaces[i]; --j) {
            str[j] = str[j - 1];
        }
        //补空格
        str[spaces[i]] = ' ';
    }
    str[len + spacesSize] = '\0';
    return str;
}

int main() {
    char s[] = "p";
    int spaces[] = { 0 };
    char* str = addSpaces(s, spaces, sizeof(spaces) / sizeof(spaces[0]));
    printf("%s\n", str);
    return 0;
}