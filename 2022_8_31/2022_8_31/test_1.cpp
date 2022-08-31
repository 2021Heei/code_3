#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
//using std::vector;
//using std::cout;
//using std::endl;
using namespace std;

int main() {
	//vector<int> ivec(10, 5);
	////cout << ivec[0] << endl;
	//vector<int> ivec2 = ivec;
	//vector<int> ivec3(ivec);
	//vector<int> ivec4{ 1,2,3,4,5,6 };
	//cout << ivec4[2] << endl;

	/*vector<int> ivec;
	for (int i = 0; i < 100; i++) {
		ivec.push_back(i);
		cout << ivec[i] << endl;
	}*/

	/*string word;
	vector<string> svec;
	int i = 0;
	while (cin >> word) {
		svec.push_back(word);
		cout << svec[i] << endl;
		++i;
	}*/

	/*vector<int> ivec{ 1,2,3,4,5,6 };
	for (auto& i : ivec)
	{
		i *= i;
	}

	for (auto i : ivec)
	{
		cout << i << " ";
	}
	cout << endl;*/


	/*vector<int> ivec2{ 1,2,3,4,5,6 };
	for(int i = 0; i < (int)(ivec2.size()); ++i){
		ivec2[i] *= ivec2[i];
}
	for (auto i : ivec2)
	{
		cout << i << " ";
	}
	cout << endl;*/

	vector<unsigned> score(11, 0);
	unsigned grade;
	while (cin >> grade) {
		if(grade <= 100)
			++score[grade / 10];
	}
	for (auto i : score) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}