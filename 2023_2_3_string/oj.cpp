#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <xstring>
#include <vector>
using namespace std;

int main01() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();


	string a = "hello world";

	string b = a;

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	string c = b;

	c = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	a = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	string str("Hello Bit.");

	str.reserve(111);

	str.resize(5);

	str.reserve(50);

	cout << str.size() << ":" << str.capacity() << endl;

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

		size_prev_pos = ++size_pos;

	}

	if (size_prev_pos != strText.size())

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;


	return 0;
}



string addStrings(string num1, string num2) {
	int len1 = num1.size() - 1;
	int len2 = num2.size() - 1;
	string str;
	int carry = 0;
	while (len1 >= 0 || len2 >= 0) {
		int n1 = 0, n2 = 0;
		if (len1 >= 0) n1 = num1[len1] - '0';
		if (len2 >= 0) n2 = num2[len2] - '0';
		int ret = n1 + n2 + carry;
		if (ret >= 10) {
			ret -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		// str+=ret+'0';
		str.insert(0, 1, ret + '0');
		len1--;
		len2--;
	}
	if (carry == 1) {
		str += '1';
		str.insert(0, 1, '1');
	}
	// reverse(str.begin(), str.end());
	return str;
}


string multiply(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	int len = len1 + len2;
	string str;
	str.reserve(len1 + len2 + 1);
	str.resize(len1 + len2, 0);
	for (int i = 0; i < str.size(); i++) {
		str[i] = '0';
	}
	for (int i = len1 - 1; i >= 0; i--) {
		int carry = 0;
		int j = len2 - 1;
		for (; j >= 0; j--) {
			int val = (num1[i] - '0') * (num2[j] - '0') + carry;
			carry = val / 10;
			val %= 10;
			int index = (len - 1) + (j - len2 + 1) + (i - len1 + 1);
			str[index] += val;
			if (str[index] > '9') {
				int tmp = str[index] - '0';
				str[index] = tmp % 10 + '0';
				str[index - 1] += tmp / 10;
			}
		}
		if (carry != 0)
			str[(len - 1) + (j - len2 + 1) + (i - len1 + 1)] += carry;
	}

	for (int i = 0; str[0] == '0' && i < len; i++) {
		if (str.size() > 1) {
			str.erase(0, 1);
		}
	}
	return str;
}

int main02() {
	//addStrings("1", "9");
	//cout << multiply("9133", "0") << endl;
	char* p = nullptr;
	//scanf("%s", p);
	const char* q = "ab";
	cout << sizeof("ab") << endl;
	cout << sizeof(const char*) << endl;
	cout << sizeof(q) << endl;
	return 0;
}

//q

void DigitToString(string& s, int number) {

	while (number != 0) {
		s += number % 10 + '0';
		number /= 10;
	}
	reverse(s.begin(), s.end());
}
int main03() {
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		str.clear();
		cin >> str;
		if (str.size() >= 10) {
			string tmp;
			tmp += str[0];

			string s;
			DigitToString(s, str.size() - 2);
			tmp += s;

			tmp += str[str.size() - 1];
			// str = tmp;
			cout << tmp << endl;
		}
		cout << str << endl;
	}
	return 0;
}

int main04()
{
	int n;
	int a1 = 1, a2 = 2;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		long long value = 0;
		if (k == 1) value = 1;
		else if (k == 2) value = 2;
		else {
			for (int i = 3; i <= k; i++) {
				cout << value << endl;
				value %= 32767;
				a1 %= 32767;
				a2 %= 32767;
				value = 2 * a2 + a1;
				a1 = a2;
				a2 = value;
			}
		}
		cout << value % 32767 << endl;


	}
	return 0;
}


