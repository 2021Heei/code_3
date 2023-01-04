#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char BTDataType;
typedef struct BTNode {
	BTDataType val;
	struct BTNode* left;//����/ǰ��
	struct BTNode* right;//�Һ���/���
	int lTag;//���־
	int rTag;//�ұ�־
	//0��ʾָ��ڵ�
	//1��ʾָ������
}BTNode;

//�����������������
BTNode* TreeCreate(BTDataType* a, int* pi) {
	//���ַ�Ϊ#ʱ��˵�������ڽڵ㣬�±��1�Լ�¼��һ��λ�ã�����NULLָ��
	if (a[(*pi)] == '#') {
		(*pi)++;
		return NULL;
	}
	//�ڵ����ʱ���ȴ������ڵ㣬��ʼ���ڵ�ָ�룬���Խڵ㸳ֵ
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		perror("malloc fail");
		return NULL;
	}
	root->left = root->right = NULL;
	root->val = a[(*pi)];
	//�ڵ㴴����ɣ��±��1�Լ�¼��һ��λ��
	(*pi)++;
	//��������ڵ㣬�������ҽڵ�
	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);

	return root;
}

////�������
//void InOrder(BTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//
//	InOrder(root->left);
//	printf("%c ", root->val);
//	InOrder(root->right);
//}

//������������� - ��������������
//������ - ������ - ��
//���򣬵�һ���ڵ�ǰ��ָ��NULL�����һ���ڵ���ָ��NULL
void InOrderThreadCreate(BTNode* root, BTNode** pprev) {
	if (root == NULL) {
		return;
	}
	
	InOrderThreadCreate(root->left, pprev);
	
	//���ڵ�ǰ�ڵ㣬�ж�ǰ��
	//��ڵ�ΪNULL��������ָ��������ָ��ǰ��
	root->lTag = root->rTag = 0;
	if (root->left == NULL) {
		root->left = *pprev;
		root->lTag = 1;
	}

	//������һ���ڵ㣬�жϺ��
	//�ҽڵ�ΪNULL������ָ����������ָ����
	if (*pprev != NULL && (*pprev)->right == NULL) {
		(*pprev)->right = root;
		(*pprev)->rTag = 1;
	}
	*pprev = root;

	InOrderThreadCreate(root->right, pprev);
}

//����root�ĺ�̽ڵ�
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

//�����������������
void InOrderThread(BTNode* root) {
	if (root == NULL) {
		return;
	}
	//������ĵ�һ���ڵ�
	BTNode* cur = root;
	while (cur->lTag == 0) {
		cur = cur->left;
	}
	printf("%c ", cur->val);
	//�������̽ڵ�
	while (cur->right!=NULL) {
		cur = NextNodeThread(cur);
		printf("%c ", cur->val);
	}
}

//�������
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
	printf("��������������������������������'#'����NULL\n");
	scanf("%s", str);*/
	int i = 0;
	BTNode* root = TreeCreate(str, &i);
	if (!root) {
		return -1;
	}
	printf("\n�������������\n");
	InOrder(root);
	printf("\n\n");
	printf("�����������ı���\n");
	BTNode* prev = NULL;
	InOrderThreadCreate(root, &prev);
	InOrderThread(root);
	printf("\n");

	TreeDestroy(root);
	return 0;
}

