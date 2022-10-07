#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
 


struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        return root;
    }
    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    //��Ϊ��
    if (root == NULL) {
        struct TreeNode* newnode =
            (struct TreeNode*)malloc(sizeof(struct TreeNode));
        assert(newnode);
        newnode->val = val;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    //����Ϊ��
    //�Ƚϣ�valС�ڣ���root��ߣ�root���ΪNULL��ֱ������ڵ���뵽root���
    //val����ͬ��
    if (val < root->val) {
        if (root->left == NULL) {
            struct TreeNode* newnode =
                (struct TreeNode*)malloc(sizeof(struct TreeNode));
            assert(newnode);
            newnode->val = val;
            newnode->left = newnode->right = NULL;
            root->left = newnode;
        }
        else {
            insertIntoBST(root->left, val);
        }
    }
    else {
        if (root->right == NULL) {
            struct TreeNode* newnode =
                (struct TreeNode*)malloc(sizeof(struct TreeNode));
            assert(newnode);
            newnode->val = val;
            newnode->left = newnode->right = NULL;
            root->right = newnode;
        }
        else {
            insertIntoBST(root->right, val);
        }
    }
    return root;
}