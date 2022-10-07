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
    //树为空
    if (root == NULL) {
        struct TreeNode* newnode =
            (struct TreeNode*)malloc(sizeof(struct TreeNode));
        assert(newnode);
        newnode->val = val;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    //树不为空
    //比较，val小于，在root左边，root左边为NULL就直接申请节点插入到root左边
    //val大于同理
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