#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Time {
public:
	int hour;
	int minute;
	int see;
};

int main() {
	Time t;
	cin >> t.hour >> t.minute >> t.see;
	cout << t.hour << ":" << t.minute << ":" << t.see << endl;
	return 0;
}