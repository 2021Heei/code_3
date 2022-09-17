#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//二叉节点
typedef char BTDataType;
typedef struct BTNode {
    BTDataType val;
    struct BTNode* left;
    struct BTNode* right;
} BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
    if (*pi == n) {
        return NULL;
    }
    if (a[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    // if (newnode == NULL) {
    //     perror("malloc file");
    //     exit(-1);
    // }
    newnode->val = a[*pi];
    (*pi)++;
    newnode->left = BinaryTreeCreate(a, n, pi);
    newnode->right = BinaryTreeCreate(a, n, pi);

    return newnode;
}

//中序遍历
void InOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }

    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

//销毁
void BinaryTreeDestory(BTNode** root) {
    assert(root);
    if (*root == NULL) {
        return;
    }
    //后序
    BinaryTreeDestory(&(*root)->left);
    BinaryTreeDestory(&(*root)->right);
    free(*root);
}

int main() {
    BTDataType str[101] = { 0 };
    while (gets(str) != NULL) {
        int num = 0;
        BTNode* root = BinaryTreeCreate(str, strlen(str), &num);
        InOrder(root);
        BinaryTreeDestory(&root);
    }
    return 0;
}