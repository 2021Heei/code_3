#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char BTDataType;
typedef struct BTNode {
	BTDataType val;
	struct BTNode* left;//左孩子/前驱
	struct BTNode* right;//右孩子/后继
	int lTag;//左标志
	int rTag;//右标志
	//0表示指向节点
	//1表示指向线索
}BTNode;

//先序遍历建立二叉树
BTNode* TreeCreate(BTDataType* a, int* pi) {
	//当字符为#时，说明不存在节点，下标加1以记录下一个位置，返回NULL指针
	if (a[(*pi)] == '#') {
		(*pi)++;
		return NULL;
	}
	//节点存在时，先创建根节点，初始化节点指针，并对节点赋值
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		perror("malloc fail");
		return NULL;
	}
	root->left = root->right = NULL;
	root->val = a[(*pi)];
	//节点创建完成，下标加1以记录下一个位置
	(*pi)++;
	//先链接左节点，再链接右节点
	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);

	return root;
}

////中序遍历
//void InOrder(BTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//
//	InOrder(root->left);
//	printf("%c ", root->val);
//	InOrder(root->right);
//}

//中序遍历线索化 - 线索二叉树创建
//左子树 - 右子树 - 根
//中序，第一个节点前驱指向NULL，最后一个节点后继指向NULL
void InOrderThreadCreate(BTNode* root, BTNode** pprev) {
	if (root == NULL) {
		return;
	}
	
	InOrderThreadCreate(root->left, pprev);
	
	//对于当前节点，判断前驱
	//左节点为NULL，则是左指针线索，指向前驱
	root->lTag = root->rTag = 0;
	if (root->left == NULL) {
		root->left = *pprev;
		root->lTag = 1;
	}

	//对于上一个节点，判断后继
	//右节点为NULL，则右指针是线索，指向后继
	if (*pprev != NULL && (*pprev)->right == NULL) {
		(*pprev)->right = root;
		(*pprev)->rTag = 1;
	}
	*pprev = root;

	InOrderThreadCreate(root->right, pprev);
}

//查找root的后继节点
BTNode* NextNodeThread(BTNode* root) {
	if (root == NULL) {
		return NULL;
	}
	BTNode* cur = root->right;
	if (root->rTag == 1) {
		return cur;
	}
	else {
		while (cur->lTag == 0) {
			cur = cur->left;
		}
		return cur;
	}
}

//线索二叉树中序遍历
void InOrderThread(BTNode* root) {
	if (root == NULL) {
		return;
	}
	//找中序的第一个节点
	BTNode* cur = root;
	while (cur->lTag == 0) {
		cur = cur->left;
	}
	printf("%c ", cur->val);
	//找中序后继节点
	while (cur->right!=NULL) {
		cur = NextNodeThread(cur);
		printf("%c ", cur->val);
	}
}

//中序遍历
void InOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

void TreeDestroy(BTNode* root) {

}

int main() {
	//char str[] = "AB#CD###E#FGH##K###";
	//char str[] = "ABD#G##E##CF###";
	//char str[] = "A#BC##D##";
	//char str[] = "1247####35##6##";

	/*char str[100] = { 0 };
	printf("请输入二叉树的先序遍历构建二叉树，'#'代表NULL\n");
	scanf("%s", str);*/
	int i = 0;
	BTNode* root = TreeCreate(str, &i);
	if (!root) {
		return -1;
	}
	printf("\n二叉树中序遍历\n");
	InOrder(root);
	printf("\n\n");
	printf("线索二叉树的遍历\n");
	BTNode* prev = NULL;
	InOrderThreadCreate(root, &prev);
	InOrderThread(root);
	printf("\n");

	TreeDestroy(root);
	return 0;
}

