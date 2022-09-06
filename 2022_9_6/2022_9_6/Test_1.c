#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


int isnum(int num) {
    int copy = num;//副本
    int bit = 0;
    while (copy) {
        bit = copy % 10;
        copy /= 10;
        if (bit == 0 || num % bit != 0) {
            return 0;
        }
    }
    return 1;
}
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int i, j;
    int* arr = (int*)malloc(sizeof(int) * 1000);
    for (i = left, j = 0; i <= right; ++i) {
        if (isnum(i)) {
            arr[j++] = i;
            ++(*returnSize);
        }
    }
    return arr;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    * returnSize = numsSize;
    int* arr = (int*)malloc(sizeof(int) * numsSize * 2);
    arr[0] = 1;
    arr[2 * numsSize - 1] = 1;
    for (int i = 1; i < numsSize; ++i) {
        arr[i] = arr[i - 1] * nums[i - 1];
    }
    for (int i = 2 * numsSize - 2; i >= numsSize; --i) {
        arr[i] = arr[i + 1] * nums[i + 1 - numsSize];
    }
    for (int i = 0; i < numsSize; ++i) {
        arr[i] = arr[i] * arr[i + numsSize];
    }
    return arr;
}
//int main() {
//    /*int arr[] = { 1,2,3,4 };
//    int size = 0;
//    int* p = productExceptSelf(arr, sizeof(arr) / sizeof(arr[0]), &size);
//    */
//
//   /* int x = -1;
//    int count = 0;*/
//    /*while (x) {
//        ++count;
//        x = x << 1;
//    }
//    printf("%d\n", count);*/
//    /*while (x) {
//        ++count;
//        x = x & (x - 1);
//    }
//    printf("%d\n", count);*/
//
//  
//    /*int w = 1, x = 2, y = 3, z = 4;
//    int ret = w < x ? w : y < z ? y : z;
//    printf("%d\n", ret);*/
//
//
//    //int a = 1, b = 2, m = 0, n = 0, k;
//    //k = (n = b < a) && (m = a);
//    //printf("%d,%d\n", k, m);
//
//    /*int a = 1500;
//    int ret = a += a -= a = 9;
//    printf("%d\n", ret);
//    double x = 10.2;
//    */
//    int i = 1;
//    sizeof(i++);
//    printf("%d\n", i);
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//int main() {
//    char str[10000] = { 0 };
//    gets(str);
//    int flag = 1;
//
//    int len = strlen(str);
//    int slow, fast;
//    char str2[10000] = { 0 };
//    for (slow = 0, fast = len - 1; fast >= 0; fast) {
//        if (isalpha(str[fast])) {
//            flag = 0;
//            str2[slow++] = str[fast];
//        }
//        else if (flag == 0) {
//            str2[slow++] = ' ';
//            flag = 1;
//        }
//    }
//    str2[slow] = '\0';
//    puts(str2);
//    return 0;
//}

//

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//void reverse(char* str, int left, int right) {
//    while (left < right) {
//        char tmp = str[left];
//        str[left] = str[right];
//        str[right] = tmp;
//        ++left;
//        --right;
//    }
//}
//
//int main() {
//    char str[10000] = "wyZksmG XY ReXA Pedt mabjlFdGmJUseHz GzciYPmv OFKis SQzQAeQexsgy ZVrsqqSbHdQF AKPJECiP vOgIXvbuJTDnpPcCD GWlPWTGQSWyaZtxHd ydpT pHSeYKetXH RdBcHmggvESwIEWlBtYq H VdkLHvSGupDEFOfH BcWxbNOQOOYYhBNEz MAFjrzTFKWZOCGGZazCn Ef owSLRoGJXMWAR pLdQQWx ZSRXXCUOSetMNfSOnRk jDhskr WHBmEifhgEEBoT CJNtdFFM n UAbfJKuoVfoqAvbEcv MnDWh";
//    /*gets(str);*/
//    int flag1 = 1;
//
//    int len = strlen(str);
//    int slow, fast;
//    char str2[10000] = { 0 };
//
//    int cnt = 0;
//    for (int i = 0; i < len; ++i) {
//        if (isalpha(str[i])) {
//            ++cnt;
//            flag1 = 0;
//        }
//        else if (flag1 == 0) {
//            flag1 = 1;
//            ++cnt;
//        }
//    }
//
//    int flag2 = 1;
//    for (slow = cnt - 1, fast = 0; fast < len; ++fast) {
//        if (isalpha(str[fast])) {
//            flag2 = 0;
//            str2[slow--] = str[fast];
//        }
//        else if (flag2 == 0) {
//            str2[slow--] = ' ';
//            flag2 = 1;
//        }
//    }
//
//    //单词逆置
//    int left = 0;
//    int right = 0;
//    /*int len2 = strlen(str2);*/
//    int flag = 1;
//    while (right <= cnt) {
//        if (isalpha(str2[right])) {
//            ++right;
//            flag = 0;
//        }
//        else {
//            reverse(str2, left, right - 1);
//            ++right;
//            left = right;
//        }
//    }
//    puts(str2);
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
////逆置相应段的元素
//void reverse(char* str, int left, int right) {
//    while (left < right) {
//        char tmp = str[left];
//        str[left] = str[right];
//        str[right] = tmp;
//        ++left;
//        --right;
//    }
//}
//
//int main() {
//    char str[10000];
//    gets(str);
//    //数组长度
//    int len = strlen(str);
//
//
//    //清理多余非字母字符
//    int slow = 0, fast = 0;
//    int flag = 1;
//    while (fast < len) {
//        if (isalpha(str[fast])) {
//            str[slow++] = str[fast];
//            flag = 0;
//        }
//        else if (flag == 0) {
//            str[slow++] = ' ';
//            flag = 1;
//        }
//        ++fast;
//    }
//    str[slow] = '\0';
//
//    //倒序字符串
//    int cnt = strlen(str);
//    reverse(str, 0, cnt-1);
//
//
//    //逐个的单个的逆置单词
//    int left = 0;
//    int right = 0;
//    flag = 1;
//    //记录每个单词的开始下标和结束下标，再逆置两个下标之间的元素
//    while (right <= cnt) {
//        if (isalpha(str[right])) {
//            ++right;
//            flag = 0;
//        }
//        else {
//            reverse(str, left, right - 1);
//            ++right;
//            left = right;
//        }
//    }
//    puts(str);
//    return 0;
//}

#include <stdio.h>

int fun(unsigned int x)
{
    int n = 0;
    while (x + 1)
    {
        n++;
        x = x | (x + 1);
    } 
    return n;
}
int main() {
    int a[10] = { 0 };
    &a[1]++;
    printf("%d\n", fun(2014));
    return 0;
}