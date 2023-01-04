#define _CRT_SECURE_NO_WARNINGS 1
//函数声明
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

//联系人类型
typedef struct PeoInfo {
	char name[MAX_NAME];
	char num[MAX_NUM];//学号
	char Class[MAX_CLASS];//班级
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
	char e_mail[MAX_E_MAIL];//邮箱
}PeoInfo;

//通讯录类型
typedef struct Contact {
	PeoInfo* peo;
	//联系人数量
	int count;
	//联系人容量
	int capacity;
}Contact;

//初始化
int InitContact(Contact* Peo);

//加载联系人信息
void LoadContact(Contact* Peo);
//菜单
void menu();

//增
void AddContact(Contact* Peo);

//打印单个联系人的信息
void print_Peo(Contact* Peo, int i);

//打印联系人
void DisplayContact(const Contact* Peo);

//名字查找
int CheckContact_by_name(Contact* Peo);

//电话查找
int CheckContact_by_tele(Contact* Peo);

//学号查找
int CheckContact_by_num(Contact* Peo);

//班级查找
int CheckContact_by_class(Contact* Peo);

//查
void CheckContact(Contact* Peo);

//删
void DelContact(Contact* Peo);

//修改联系人信息
void ModifyContact(Contact* Peo);

//排序
void sort(Contact* Peo);

//保存通讯录信息
void SaveContact(Contact* Peo);

//销毁通讯录
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
		printf("请输入你的选择>");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			//add
			AddContact(&Peo);
			break;
		case DELETE:
			//删
			DelContact(&Peo);
			break;
		case CHECK:
			//查
			CheckContact(&Peo);
			break;
		case MODIFY:
			//改
			ModifyContact(&Peo);
			break;
		case DISPLAY:
			//打印
			DisplayContact(&Peo);
			break;
		case SORT:
			//排序
			sort(&Peo);
			break;
		case EXIT:
			//销毁通讯录并退出
			SaveContact(&Peo);
			DestroyContact(&Peo);
			printf("程序退出!\n");
			break;
		default:
			//其他
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (input);
	return 0;
}





//扩容
void CheckCapacityContact(Contact* Peo) {
	assert(Peo != NULL);
	if (Peo->count == Peo->capacity) {
		//扩容时是  以前的容量  加上  新增的容量
		PeoInfo* p = (PeoInfo*)realloc(Peo->peo, sizeof(PeoInfo) * (Peo->capacity + CAPACITY_ADD));
		if (p == NULL) {
			//扩容失败
			printf("CheckCapacityContact%s", strerror(errno));
		}
		//成功
		Peo->peo = p;
		Peo->capacity += CAPACITY_ADD;
		printf("扩容成功\n");
	}
}

//加载联系人信息
void LoadContact(Contact* Peo) {
	assert(Peo != NULL);
	//打开文件
	FILE* pf = fopen("Contact.txt", "rb");
	//判断文件是否打开成功
	if (pf == NULL) {
		perror("LoadContact");
		return;
	}
	//二进制形式读取文件信息
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf) == 1) {
		//判断是否增容
		CheckCapacityContact(Peo);
		Peo->peo[Peo->count] = tmp;
		Peo->count++;
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}
//初始化结构体
int InitContact(Contact* Peo) {
	assert(Peo != NULL);
	//初始化
	PeoInfo* p = (PeoInfo*)calloc(INIT_SZ, sizeof(PeoInfo));
	//初始化分配内存空间失败,返回1
	if (p == NULL) {
		printf("InitContact::%s", strerror(errno));
		return 1;
	}
	//成功
	Peo->peo = p;
	Peo->count = 0;
	Peo->capacity = INIT_SZ;
	//加载文件信息到通讯录
	LoadContact(Peo);

	return 0;
}
//菜单
void menu() {
	printf("**********************************\n");
	printf("******  1.增加     2.删除   ******\n");
	printf("******  3.查询     4.修改   ******\n");
	printf("******  5.浏览     6.排序   ******\n");
	printf("******        0.exit        ******\n");
	printf("**********************************\n");
}

//增
void AddContact(Contact* Peo) {
	assert(Peo != NULL);
	//扩充容量
	CheckCapacityContact(Peo);

	printf("请输入联系人姓名>");
	scanf("%s", Peo->peo[Peo->count].name);

	printf("请输入联系人学号>");
	scanf("%s", Peo->peo[Peo->count].num);
	printf("请输入联系人班级>");
	scanf("%s", Peo->peo[Peo->count].Class);

	printf("请输入联系人年龄>");
	scanf("%d", &(Peo->peo[Peo->count].age));
	printf("请输入联系人性别>");
	scanf("%s", Peo->peo[Peo->count].sex);
	printf("请输入联系人电话>");
	scanf("%s", Peo->peo[Peo->count].tele);
	printf("请输入联系人地址>");
	scanf("%s", Peo->peo[Peo->count].address);

	printf("请输入联系人邮箱>");
	scanf("%s", Peo->peo[Peo->count].e_mail);
	Peo->count++;
	printf("增加联系人成功!\n");
}

//打印单个联系人的信息
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
//打印联系人
void DisplayContact(const Contact* Peo) {
	assert(Peo != NULL);
	int i = 0;
	printf("%-20s %-15s %-15s %-4s %-6s %-15s %-30s %-20s\n",
		"姓名", "学号", "班级", "年龄", "性别", "电话", "地址", "邮箱");
	for (i = 0; i < Peo->count; i++) {
		printf_Peo(Peo, i);
	}
}

//名字查找
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

//电话查找
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

//学号查找
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

//班级查找
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



//查
void CheckContact(Contact* Peo) {
	assert(Peo != NULL);
	int index = 0;
	printf("请选择查找的方式(1/2)\n"
		"1. by_name\n"
		"2. by_tele\n"
		"3. by_num\n"
		"4. by_class\n");
	scanf("%d", &index);
	int sub = 0;
	switch (index) {
	case 1:
		printf("请输入联系人姓名>");
		sub = CheckContact_by_name(Peo);//subscript下标
		if (sub >= 0) {
			printf("找到了!\n");
			printf_Peo(Peo, sub);
		}
		else {
			printf("没找到!\n");
		}
		break;
	case 2:
		printf("请输入联系人电话>");
		sub = CheckContact_by_tele(Peo);
		if (sub >= 0) {
			printf("找到了!\n");
			printf_Peo(Peo, sub);
		}
		else {
			printf("没找到!\n");
		}
		break;
	case 3:
		printf("请输入联系人学号>");
		sub = CheckContact_by_num(Peo);
		if (sub >= 0) {
			printf("找到了!\n");
			printf_Peo(Peo, sub);
		}
		else {
			printf("没找到!\n");
		}
		break;
	case 4:
		printf("请输入联系人班级>");
		sub = CheckContact_by_class(Peo);
		if (sub >= 0) {
			printf("找到了!\n");
			printf_Peo(Peo, sub);
		}
		else {
			printf("没找到!\n");
		}
		break;
	default:
		printf("输入错误!\n");
		break;
	}
}

//删
void DelContact(Contact* Peo) {
	assert(Peo != NULL);
	printf("请输入要删除的联系人姓名>");
	//名字查找一个联系人
	int index = CheckContact_by_name(Peo);
	if (index >= 0) {
		int i = 0;
		for (i = index; i < Peo->count - 1; i++) {
			Peo->peo[i] = Peo->peo[i + 1];
		}
		Peo->count--;
		printf("删除联系人成功!\n");
	}
	else {
		printf("删除失败，联系人不存在!\n");
	}
}

//修改联系人信息
void ModifyContact(Contact* Peo) {
	assert(Peo != NULL);
	//查
	printf("请输入要修改的联系人姓名>");
	int index = CheckContact_by_name(Peo);
	if (index >= 0) {
		printf("请输入联系人姓名>");
		scanf("%s", Peo->peo[index].name);

		printf("请输入联系人学号>");
		scanf("%s", Peo->peo[index].num);
		printf("请输入联系人班级>");
		scanf("%s", Peo->peo[index].Class);

		printf("请输入联系人年龄>");
		scanf("%d", &(Peo->peo[index].age));
		printf("请输入联系人性别>");
		scanf("%s", Peo->peo[index].sex);
		printf("请输入联系人电话>");
		scanf("%s", Peo->peo[index].tele);
		printf("请输入联系人地址>");
		scanf("%s", Peo->peo[index].address);

		printf("请输入联系人邮箱>");
		scanf("%s", Peo->peo[index].e_mail);
		printf("修改联系人成功!\n");
	}
	else {
		printf("联系人不存在，修改失败\n");
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
//排序
void sort(Contact* Peo) {
	assert(Peo != NULL);
	printf("请输入选择排序的选择:\n"
		"1.按姓名升序排列\n"
		"2.按姓名降序排列\n"
		"3.按年龄升序排列\n"
		"4.按年龄降序排列\n");
	int input = 0;
	scanf("%d", &input);
	int (*cmp[4])(const void* e1, const void* e2) = {
		cmp_name_up,
		cmp_name_down,
		cmp_age_up,
		cmp_age_down };
	qsort(Peo->peo, Peo->count, sizeof(Peo->peo[0]), cmp[input - 1]);
	printf("排序成功!\n");
}
//保存通讯录信息
void SaveContact(const Contact* Peo) {
	assert(Peo != NULL);
	//以只写的模式打开文件
	FILE* pf = fopen("Contact.txt", "wb");
	//判断文件是否打开成功
	if (pf == NULL) {
		perror("SaveContact");
		return;
	}
	//二进制形式保存信息，写入到文件
	int i = 0;
	for (i = 0; i < Peo->count; i++) {
		fwrite(Peo->peo + i, sizeof(PeoInfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//销毁通讯录
void DestroyContact(Contact* Peo) {
	assert(Peo != NULL);
	free(Peo->peo);
	Peo->peo = NULL;
}
