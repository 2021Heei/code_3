#include <iostream>
#include <string>

using namespace std;

class student {
public:
	string name;
	string sex;
	int num;
	int score;
	string Class;
	string major;
	student(string name1 = "", string sex1 = "", int num1 = 0, int score1 = 0, string Class1 = "", string major1 = "") {
		name = name1;
		sex = sex1;
		num = num1;
		score = score1;
		Class = Class1;
		major = major1;
	}
	void InPut() {
		cout << "请输入姓名:>";
		cin >> name;
		cout << endl;
		cout << "请输入性别:>";
		cin >> sex;
		cout << endl;
		cout << "请输入学号:>";
		cin >> num;
		cout << endl; 
		cout << "请输入成绩:>";
		cin >> score;
		cout << endl;
		cout << "请输入班级:>";
		cin >> Class;
		cout << endl;
		cout << "请输入专业:>";
		cin >> major;
		cout << endl;
	}
	void Output() {
		cout << "姓名: ";
		cout << name << endl;
		cout << "性别: ";
		cout << sex << endl;
		cout << "学号: ";
		cout << num << endl;
		cout << "成绩: ";
		cout << score << endl;
		cout << "班级: ";
		cout << Class << endl;
		cout << "专业: ";
		cout << major << endl;
	}
};

void init(student& a) {
}



int main() {
	student* a = NULL;
	for (int i = 0; i < 3; ++i) {
		a[i].InPut();
	}
	for (int i = 0; i < 3; ++i) {
		a[i].Output();
	}
	delete a;
	return 0;
}