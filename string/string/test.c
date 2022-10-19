#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//bool isVowels(char ch) {
//    if (ch == 'a' ||
//        ch == 'e' ||
//        ch == 'i' ||
//        ch == 'o' ||
//        ch == 'u' ||
//        ch == 'A' ||
//        ch == 'E' ||
//        ch == 'I' ||
//        ch == 'O' ||
//        ch == 'U') {
//        return true;
//    }
//    return false;
//}
//void Swap(char* cp1, char* cp2) {
//    char tmp = *cp1;
//    *cp1 = *cp2;
//    *cp2 = tmp;
//}
//char* reverseVowels(char* s) {
//    int len = strlen(s);
//    char* left = s;
//    char* right = s + len - 1;
//    while (left < right) {
//        while (left < right && !isVowels(*left)) {
//            ++left;
//        }
//        while (left < right && !isVowels(*right)) {
//            --right;
//        }
//        if (left < right){
//            Swap(left, right);
//            ++left;
//            --right;
//    }
//    }
//
//    return s;
//}



//int main() {
//    char str[] = "hello";
//    char* cp = reverseVowels(str);
//    printf("%s", cp);
//    return 0;
//}
int cmp(void* e1, void* e2) {
    return *(char*)e2 - *(char*)e1;
}

bool isSort(char* cp) {
    qsort(cp, 256, 1, cmp);
    for (int i = 0; i < 256; ++i) {
        if (cp[i] == cp[i + 1] && cp[i] != '\0') {
            //ÓÐÖØ¸´
            return true;
        }
    }
    return false;
}

bool isIsomorphic(char* s, char* t) {
    char str[256] = { 0 };
    
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (str[s[i]] == '\0') {
            str[s[i]] = t[i];
        }
    }
    char ch[256] = { 0 };
    memcpy(ch, str, 256);
    if (isSort(ch)) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (t[i] != str[s[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    char* s = "badc";
    char* t = "baba";
    int ret = isIsomorphic(s, t);
    printf("%d\n", ret);
    return 0;
}