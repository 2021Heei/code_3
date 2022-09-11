#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Student {
public:
	char name[20];
	char num[20];
	int score;
};

int main() {
	Student s;
	cin >> s.name >> s.num >> s.score;
	cout << s.name << " " << s.num << " " << s.score << endl;
	return 0;
}