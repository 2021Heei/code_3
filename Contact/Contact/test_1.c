#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
//��������
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define INIT_SZ 3
#define CAPACITY_ADD 2
#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 15
#define MAX_ADDRESS 30


//��ϵ������
typedef struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}PeoInfo;

//ͨѶ¼����
typedef struct Contact {
	PeoInfo* peo;
	//��ϵ������
	int count;
	//��ϵ������
	int capacity;
}Contact;

//��ʼ��
int InitContact(Contact* Peo);

//�˵�
void menu();

//��
void AddContact(Contact* Peo);

//��ӡ������ϵ�˵���Ϣ
void print_Peo(Contact* Peo, int i);

//��ӡ��ϵ��
void DisplayContact(const Contact* Peo);

//���ֲ���
int CheckContact_by_name(Contact* Peo, char* pname);

//�绰����
int CheckContact_by_tele(Contact* Peo);

//��
void CheckContact(Contact* Peo);

//ɾ
void DelContact(Contact* Peo);

//�޸���ϵ����Ϣ
void ModifyContact(Contact* Peo);

//����
void sort(Contact* Peo);

//����ͨѶ¼
void DestroyContact(Contact* Peo);




//���Բ���
//��̬ͨѶ¼


enum option {
	EXIT,
	ADD,
	DELETE,
	CHECK,
	MODIFY,
	DISPLAY,
	SORT,
};
int main() {
	Contact Peo;
	int input = 0;

	InitContact(&Peo);

	do {
		menu();
		printf("���������ѡ��>");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			//add
			AddContact(&Peo);
			break;
		case DELETE:
			//ɾ
			DelContact(&Peo);
			break;
		case CHECK:
			//��
			CheckContact(&Peo);
			break;
		case MODIFY:
			//��
			ModifyContact(&Peo);
			break;
		case DISPLAY:
			//��ӡ
			DisplayContact(&Peo);
			break;
		case SORT:
			//����
			sort(&Peo);
			break;
		case EXIT:
			//����ͨѶ¼���˳�
			DestroyContact(&Peo);
			printf("�����˳�!\n");
			break;
		default:
			//����
			printf("�����������������!\n");
			break;
		}
	} while (input);
	return 0;
}



//��������

//��ʼ���ṹ��
int InitContact(Contact* Peo) {
	assert(Peo != NULL);
	//��ʼ��
	PeoInfo* p = (PeoInfo*)calloc(INIT_SZ, sizeof(PeoInfo));
	//��ʼ�������ڴ�ռ�ʧ��,����1
	if (p == NULL) {
		printf("InitContact::%s", strerror(errno));
		return 1;
	}
	//�ɹ�
	Peo->peo = p;
	Peo->count = 0;
	Peo->capacity = INIT_SZ;
	return 0;
}
//�˵�
void menu() {
	printf("******************************\n");
	printf("****   1. ��      2. ɾ   ****\n");
	printf("****   3. ��      4. ��   ****\n");
	printf("****  5.��ӡ      6.����  ****\n");
	printf("****        0.exit        ****\n");
	printf("******************************\n");
}

//����
void CapacityContact(Contact* Peo) {
	assert(Peo != NULL);
	//����ʱ��  ��ǰ������  ����  ����������
	PeoInfo* p = (PeoInfo*)realloc(Peo->peo, sizeof(PeoInfo) * (Peo->capacity + CAPACITY_ADD));
	if (p == NULL) {
		//����ʧ��
		printf("CapacityContact%s", strerror(errno));
	}
	//�ɹ�
	Peo->peo = p;
	Peo->capacity += CAPACITY_ADD;
	printf("���ݳɹ�\n");
}
//��
void AddContact(Contact* Peo) {
	assert(Peo != NULL);
	if (Peo->count == Peo->capacity) {
		//��������
		CapacityContact(Peo);
	}
	printf("��������ϵ������>");
	scanf("%s", Peo->peo[Peo->count].name);
	printf("��������ϵ������>");
	scanf("%d", &(Peo->peo[Peo->count].age));
	printf("��������ϵ���Ա�>");
	scanf("%s", Peo->peo[Peo->count].sex);
	printf("��������ϵ�˵绰>");
	scanf("%s", Peo->peo[Peo->count].tele);
	printf("��������ϵ�˵�ַ>");
	scanf("%s", Peo->peo[Peo->count].address);
	Peo->count++;
	printf("������ϵ�˳ɹ�!\n");
}

//��ӡ������ϵ�˵���Ϣ
void printf_Peo(const Contact* Peo, int i) {
	assert(Peo != NULL);
	printf("%-20s %-4d %-6s %-15s %-30s\n",
		Peo->peo[i].name,
		Peo->peo[i].age,
		Peo->peo[i].sex,
		Peo->peo[i].tele,
		Peo->peo[i].address);
}
//��ӡ��ϵ��
void DisplayContact(const Contact* Peo) {
	assert(Peo != NULL);
	int i = 0;
	printf("%-20s %-4s %-6s %-15s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < Peo->count; i++) {
		printf_Peo(Peo, i);
	}
}

//���ֲ���
int CheckContact_by_name(Contact* Peo) {
	assert(Peo != NULL);
	char tmp[MAX_NAME] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < Peo->count; i++) {
		if (strcmp(Peo->peo[i].name, tmp) == 0) {
			return i;
		}
	}
	return -1;
}

//�绰����
int CheckContact_by_tele(Contact* Peo) {
	assert(Peo != NULL);
	char tmp[MAX_NAME] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < Peo->count; i++) {
		if (strcmp(Peo->peo[i].tele, tmp) == 0) {
			return i;
		}
	}
	return -1;
}

//��
void CheckContact(Contact* Peo) {
	assert(Peo != NULL);
	int index = 0;
	printf("��ѡ����ҵķ�ʽ(1/2)\n"
		"1. by_name\n"
		"2. by_tele\n");
	scanf("%d", &index);
	int sub = 0;
	switch (index) {
	case 1:
		printf("��������ϵ������>");
		sub = CheckContact_by_name(Peo);//subscript�±�
		if (sub >= 0) {
			printf("�ҵ���!\n");
			printf_Peo(Peo, sub);
		}
		else {
			printf("û�ҵ�!\n");
		}
		break;
	case 2:
		printf("��������ϵ�˵绰>");
		sub = CheckContact_by_tele(Peo);
		if (sub >= 0) {
			printf("�ҵ���!\n");
			printf_Peo(Peo, sub);
		}
		else {
			printf("û�ҵ�!\n");
		}
		break;
	default:
		printf("�������!\n");
		break;
	}

}
//ɾ
void DelContact(Contact* Peo) {
	assert(Peo != NULL);
	printf("������Ҫɾ������ϵ������>");
	//���ֲ���һ����ϵ��
	int index = CheckContact_by_name(Peo);
	if (index >= 0) {
		int i = 0;
		for (i = index; i < Peo->count - 1; i++) {
			Peo->peo[i] = Peo->peo[i + 1];
		}
		Peo->count--;
		printf("ɾ����ϵ�˳ɹ�!\n");
	}
	else {
		printf("ɾ��ʧ�ܣ���ϵ�˲�����!\n");
	}
}

//�޸���ϵ����Ϣ
void ModifyContact(Contact* Peo) {
	assert(Peo != NULL);
	//��
	printf("������Ҫ�޸ĵ���ϵ������>");
	int index = CheckContact_by_name(Peo);
	if (index >= 0) {
		printf("��������ϵ������>");
		scanf("%s", Peo->peo[index].name);
		printf("��������ϵ������>");
		scanf("%d", &(Peo->peo[index].age));
		printf("��������ϵ���Ա�>");
		scanf("%s", Peo->peo[index].sex);
		printf("��������ϵ�˵绰>");
		scanf("%s", Peo->peo[index].tele);
		printf("��������ϵ�˵�ַ>");
		scanf("%s", Peo->peo[index].address);
		printf("�޸���ϵ�˳ɹ�!\n");
	}
	else {
		printf("��ϵ�˲����ڣ��޸�ʧ��\n");
	}
}

int cmp_name_up(const void* e1, const void* e2) {
	assert(e1 != NULL && e2 != NULL);
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
int cmp_name_down(const void* e1, const void* e2) {
	assert(e1 != NULL && e2 != NULL);
	return strcmp(((PeoInfo*)e2)->name, ((PeoInfo*)e1)->name);
}
int cmp_age_up(const void* e1, const void* e2) {
	assert(e1 != NULL && e2 != NULL);
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}
int cmp_age_down(const void* e1, const void* e2) {
	assert(e1 != NULL && e2 != NULL);
	return ((PeoInfo*)e2)->age - ((PeoInfo*)e1)->age;
}
//����
void sort(Contact* Peo) {
	assert(Peo != NULL);
	printf("������ѡ�������ѡ��:\n"
		"1.��������������\n"
		"2.��������������\n"
		"3.��������������\n"
		"4.�����併������\n");
	int input = 0;
	scanf("%d", &input);
	int (*cmp[5])(const void* e1, const void* e2) = {
		0,
		cmp_name_up,
		cmp_name_down,
		cmp_age_up,
		cmp_age_down };
	qsort(Peo->peo, Peo->count, sizeof(Peo->peo[0]), cmp[input]);
	printf("����ɹ�!\n");
}

//����ͨѶ¼
void DestroyContact(Contact* Peo) {
	assert(Peo != NULL);
	free(Peo->peo);
	Peo->peo = NULL;
}


