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
int CheckContact_by_name(Contact* Peo);

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
