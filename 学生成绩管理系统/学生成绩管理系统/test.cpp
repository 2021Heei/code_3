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
		cout << "����������:>";
		cin >> name;
		cout << endl;
		cout << "�������Ա�:>";
		cin >> sex;
		cout << endl;
		cout << "������ѧ��:>";
		cin >> num;
		cout << endl; 
		cout << "������ɼ�:>";
		cin >> score;
		cout << endl;
		cout << "������༶:>";
		cin >> Class;
		cout << endl;
		cout << "������רҵ:>";
		cin >> major;
		cout << endl;
	}
	void Output() {
		cout << "����: ";
		cout << name << endl;
		cout << "�Ա�: ";
		cout << sex << endl;
		cout << "ѧ��: ";
		cout << num << endl;
		cout << "�ɼ�: ";
		cout << score << endl;
		cout << "�༶: ";
		cout << Class << endl;
		cout << "רҵ: ";
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