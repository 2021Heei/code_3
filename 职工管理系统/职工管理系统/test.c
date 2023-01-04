#define _CRT_SECURE_NO_WARNINGS 1
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
#define MAX_NUM 15
#define MAX_CLASS 15
#define MAX_E_MAIL 20

//��ϵ������
typedef struct PeoInfo {
	char name[MAX_NAME];
	char num[MAX_NUM];//ѧ��
	char Class[MAX_CLASS];//�༶
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
	char e_mail[MAX_E_MAIL];//����
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

//������ϵ����Ϣ
void LoadContact(Contact* Peo);
//�˵�
void menu();

//��
void AddContact(Contact* Peo);

//��ӡ������ϵ�˵���Ϣ
void print_Peo(Contact* Peo, int i);

//��ӡ��ϵ��
void DisplayContact(const Contact* Peo);

//���ֲ���
int CheckContact_by_name(Contact* Peo);

//�绰����
int CheckContact_by_tele(Contact* Peo);

//ѧ�Ų���
int CheckContact_by_num(Contact* Peo);

//�༶����
int CheckContact_by_class(Contact* Peo);

//��
void CheckContact(Contact* Peo);

//ɾ
void DelContact(Contact* Peo);

//�޸���ϵ����Ϣ
void ModifyContact(Contact* Peo);

//����
void sort(Contact* Peo);

//����ͨѶ¼��Ϣ
void SaveContact(Contact* Peo);

//����ͨѶ¼
void DestroyContact(Contact* Peo);




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
			SaveContact(&Peo);
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





//����
void CheckCapacityContact(Contact* Peo) {
	assert(Peo != NULL);
	if (Peo->count == Peo->capacity) {
		//����ʱ��  ��ǰ������  ����  ����������
		PeoInfo* p = (PeoInfo*)realloc(Peo->peo, sizeof(PeoInfo) * (Peo->capacity + CAPACITY_ADD));
		if (p == NULL) {
			//����ʧ��
			printf("CheckCapacityContact%s", strerror(errno));
		}
		//�ɹ�
		Peo->peo = p;
		Peo->capacity += CAPACITY_ADD;
		printf("���ݳɹ�\n");
	}
}

//������ϵ����Ϣ
void LoadContact(Contact* Peo) {
	assert(Peo != NULL);
	//���ļ�
	FILE* pf = fopen("Contact.txt", "rb");
	//�ж��ļ��Ƿ�򿪳ɹ�
	if (pf == NULL) {
		perror("LoadContact");
		return;
	}
	//��������ʽ��ȡ�ļ���Ϣ
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf) == 1) {
		//�ж��Ƿ�����
		CheckCapacityContact(Peo);
		Peo->peo[Peo->count] = tmp;
		Peo->count++;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
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
	//�����ļ���Ϣ��ͨѶ¼
	LoadContact(Peo);

	return 0;
}
//�˵�
void menu() {
	printf("**********************************\n");
	printf("******  1.����     2.ɾ��   ******\n");
	printf("******  3.��ѯ     4.�޸�   ******\n");
	printf("******  5.���     6.����   ******\n");
	printf("******        0.exit        ******\n");
	printf("**********************************\n");
}

//��
void AddContact(Contact* Peo) {
	assert(Peo != NULL);
	//��������
	CheckCapacityContact(Peo);

	printf("��������ϵ������>");
	scanf("%s", Peo->peo[Peo->count].name);

	printf("��������ϵ��ѧ��>");
	scanf("%s", Peo->peo[Peo->count].num);
	printf("��������ϵ�˰༶>");
	scanf("%s", Peo->peo[Peo->count].Class);

	printf("��������ϵ������>");
	scanf("%d", &(Peo->peo[Peo->count].age));
	printf("��������ϵ���Ա�>");
	scanf("%s", Peo->peo[Peo->count].sex);
	printf("��������ϵ�˵绰>");
	scanf("%s", Peo->peo[Peo->count].tele);
	printf("��������ϵ�˵�ַ>");
	scanf("%s", Peo->peo[Peo->count].address);

	printf("��������ϵ������>");
	scanf("%s", Peo->peo[Peo->count].e_mail);
	Peo->count++;
	printf("������ϵ�˳ɹ�!\n");
}

//��ӡ������ϵ�˵���Ϣ
void printf_Peo(const Contact* Peo, int i) {
	assert(Peo != NULL);
	printf("%-20s %-15s %-15s %-4d %-6s %-15s %-30s %-20s\n",
		Peo->peo[i].name,
		Peo->peo[i].num,
		Peo->peo[i].Class,
		Peo->peo[i].age,
		Peo->peo[i].sex,
		Peo->peo[i].tele,
		Peo->peo[i].address,
		Peo->peo[i].e_mail);
}
//��ӡ��ϵ��
void DisplayContact(const Contact* Peo) {
	assert(Peo != NULL);
	int i = 0;
	printf("%-20s %-15s %-15s %-4s %-6s %-15s %-30s %-20s\n",
		"����", "ѧ��", "�༶", "����", "�Ա�", "�绰", "��ַ", "����");
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

//ѧ�Ų���
int CheckContact_by_num(Contact* Peo) {
	assert(Peo != NULL);
	char tmp[MAX_NUM] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < Peo->count; i++) {
		if (strcmp(Peo->peo[i].num, tmp) == 0) {
			return i;
		}
	}
	return -1;
}

//�༶����
int CheckContact_by_class(Contact* Peo) {
	assert(Peo != NULL);
	char tmp[MAX_CLASS] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < Peo->count; i++) {
		if (strcmp(Peo->peo[i].Class, tmp) == 0) {
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
		"2. by_tele\n"
		"3. by_num\n"
		"4. by_class\n");
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
	case 3:
		printf("��������ϵ��ѧ��>");
		sub = CheckContact_by_num(Peo);
		if (sub >= 0) {
			printf("�ҵ���!\n");
			printf_Peo(Peo, sub);
		}
		else {
			printf("û�ҵ�!\n");
		}
		break;
	case 4:
		printf("��������ϵ�˰༶>");
		sub = CheckContact_by_class(Peo);
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

		printf("��������ϵ��ѧ��>");
		scanf("%s", Peo->peo[index].num);
		printf("��������ϵ�˰༶>");
		scanf("%s", Peo->peo[index].Class);

		printf("��������ϵ������>");
		scanf("%d", &(Peo->peo[index].age));
		printf("��������ϵ���Ա�>");
		scanf("%s", Peo->peo[index].sex);
		printf("��������ϵ�˵绰>");
		scanf("%s", Peo->peo[index].tele);
		printf("��������ϵ�˵�ַ>");
		scanf("%s", Peo->peo[index].address);

		printf("��������ϵ������>");
		scanf("%s", Peo->peo[index].e_mail);
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
	int (*cmp[4])(const void* e1, const void* e2) = {
		cmp_name_up,
		cmp_name_down,
		cmp_age_up,
		cmp_age_down };
	qsort(Peo->peo, Peo->count, sizeof(Peo->peo[0]), cmp[input - 1]);
	printf("����ɹ�!\n");
}
//����ͨѶ¼��Ϣ
void SaveContact(const Contact* Peo) {
	assert(Peo != NULL);
	//��ֻд��ģʽ���ļ�
	FILE* pf = fopen("Contact.txt", "wb");
	//�ж��ļ��Ƿ�򿪳ɹ�
	if (pf == NULL) {
		perror("SaveContact");
		return;
	}
	//��������ʽ������Ϣ��д�뵽�ļ�
	int i = 0;
	for (i = 0; i < Peo->count; i++) {
		fwrite(Peo->peo + i, sizeof(PeoInfo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//����ͨѶ¼
void DestroyContact(Contact* Peo) {
	assert(Peo != NULL);
	free(Peo->peo);
	Peo->peo = NULL;
}
