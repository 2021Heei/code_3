#include "contact.h"
//函数定义

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
	return 0;
}
//菜单
void menu() {
	printf("******************************\n");
	printf("****   1. 增      2. 删   ****\n");
	printf("****   3. 查      4. 改   ****\n");
	printf("****  5.打印      6.排序  ****\n");
	printf("****        0.exit        ****\n");
	printf("******************************\n");
}

//扩容
void CapacityContact(Contact* Peo) {
	assert(Peo != NULL);
	//扩容时是  以前的容量  加上  新增的容量
	PeoInfo* p = (PeoInfo*)realloc(Peo->peo, sizeof(PeoInfo) * (Peo->capacity + CAPACITY_ADD));
	if (p == NULL) {
		//扩容失败
		printf("CapacityContact%s", strerror(errno));
	}
	//成功
	Peo->peo = p;
	Peo->capacity += CAPACITY_ADD;
	printf("扩容成功\n");
}
//增
void AddContact(Contact* Peo) {
	assert(Peo != NULL);
	if (Peo->count == Peo->capacity) {
		//扩充容量
		CapacityContact(Peo);
	}
	printf("请输入联系人姓名>");
	scanf("%s", Peo->peo[Peo->count].name);
	printf("请输入联系人年龄>");
	scanf("%d", &(Peo->peo[Peo->count].age));
	printf("请输入联系人性别>");
	scanf("%s", Peo->peo[Peo->count].sex);
	printf("请输入联系人电话>");
	scanf("%s", Peo->peo[Peo->count].tele);
	printf("请输入联系人地址>");
	scanf("%s", Peo->peo[Peo->count].address);
	Peo->count++;
	printf("增加联系人成功!\n");
}

//打印单个联系人的信息
void printf_Peo(const Contact* Peo, int i) {
	assert(Peo != NULL);
	printf("%-20s %-4d %-6s %-15s %-30s\n",
		Peo->peo[i].name,
		Peo->peo[i].age,
		Peo->peo[i].sex,
		Peo->peo[i].tele,
		Peo->peo[i].address);
}
//打印联系人
void DisplayContact(const Contact* Peo) {
	assert(Peo != NULL);
	int i = 0;
	printf("%-20s %-4s %-6s %-15s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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

//查
void CheckContact(Contact* Peo) {
	assert(Peo != NULL);
	int index = 0;
	printf("请选择查找的方式(1/2)\n"
		"1. by_name\n"
		"2. by_tele\n");
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
		printf("请输入联系人年龄>");
		scanf("%d", &(Peo->peo[index].age));
		printf("请输入联系人性别>");
		scanf("%s", Peo->peo[index].sex);
		printf("请输入联系人电话>");
		scanf("%s", Peo->peo[index].tele);
		printf("请输入联系人地址>");
		scanf("%s", Peo->peo[index].address);
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
	qsort(Peo, Peo->count, sizeof(Peo->peo[0]), cmp[input - 1]);
	printf("排序成功!\n");
}
//销毁通讯录
void DestroyContact(Contact* Peo) {
	assert(Peo != NULL);
	free(Peo->peo);
	Peo->peo = NULL;
}