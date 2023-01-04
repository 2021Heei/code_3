//#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
////函数声明
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//#include <stdlib.h>
//#include <errno.h>
//
//#define INIT_SZ 3
//#define CAPACITY_ADD 2
//#define MAX_NAME 20
//#define MAX_SEX 6
//#define MAX_TELE 15
//#define MAX_ADDRESS 30
//#define MAX_NUM 15
//#define MAX_CLASS 15
//#define MAX_E_MAIL 20
//
////联系人类型
//typedef struct PeoInfo {
//	char name[MAX_NAME];
//	char num[MAX_NUM];//学号
//	char Class[MAX_CLASS];//班级
//	int age;
//	char sex[MAX_SEX];
//	char tele[MAX_TELE];
//	char address[MAX_ADDRESS];
//	char e_mail[MAX_E_MAIL];//邮箱
//}PeoInfo;
//
////通讯录类型
//typedef struct Contact {
//	PeoInfo* peo;
//	//联系人数量
//	int count;
//	//联系人容量
//	int capacity;
//}Contact;
//
////初始化
//int InitContact(Contact* Peo);
//
////加载联系人信息
//void LoadContact(Contact* Peo);
////菜单
//void menu();
//
////增
//void AddContact(Contact* Peo);
//
////打印单个联系人的信息
//void print_Peo(Contact* Peo, int i);
//
////打印联系人
//void DisplayContact(const Contact* Peo);
//
////名字查找
//int CheckContact_by_name(Contact* Peo);
//
////电话查找
//int CheckContact_by_tele(Contact* Peo);
//
////学号查找
//int CheckContact_by_num(Contact* Peo);
//
////班级查找
//int CheckContact_by_class(Contact* Peo);
//
////查
//void CheckContact(Contact* Peo);
//
////删
//void DelContact(Contact* Peo);
//
////修改联系人信息
//void ModifyContact(Contact* Peo);
//
////排序
//void sort(Contact* Peo);
//
////保存通讯录信息
//void SaveContact(Contact* Peo);
//
////销毁通讯录
//void DestroyContact(Contact* Peo);
//
//
