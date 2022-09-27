#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//int main() {
//	int v1 = 5, v2 = 6;
//	//std::cin >> v1 >> v2;
//	/*std::cout << v1 << " " << v2 << " " << v1 + v2 << std::endl;
//	std::cout << v1 * v2 << std::endl;
//	std::cout << "Hello,world" << std::endl;*/
//	//std::cout << "/*";
//	//
//	//std::cout << 
//	//std::cout << /* "*/" /* "/*" */;
//
//	return 0;
//}


//int main() {
//	/*int sum = 0, val = 1;
//	while (val <= 10) {
//		sum += val;
//		++val;
//	}
//	std::cout << sum << std::endl;*/
//	int n = 0, sum = 0;
//	while (n <= 100) {
//		sum += n;
//		++n;
//	}
//
//	std::cout << sum << std::endl;
//	return 0;
//}

//int main() {
//	/*int n = 110;
//	while (n--) {
//		std::cout << n << " ";
//	}
//	std::cout << std::endl;*/
//	/*int n, m;
//	std::cin >> n >> m;
//	while (n <= m) {
//		std::cout << n << " ";
//		++n;
//	}
//	std::cout << std::endl;*/
//
//
//	return 0;
//}

//int main() {
//	int currentval = 0, val;
//	if (std::cin >> currentval) {
//		int cnt = 1;
//		while (std::cin >> val) {
//			if (val == currentval) {
//				++cnt;
//			}
//			else {
//				std::cout << currentval << " is " << cnt << " times " << std::endl;
//				cnt = 1;
//				currentval = val;
//			}
//		}
//		std::cout << currentval * 10 << std::endl;
//		std::cout << currentval << " is " << cnt << " times " << std::endl;
//	}
//	return 0;
//}

//int main() {
//	int n, m;
//	std::cin >> n >> m;
//	int min = n;
//	int max = m;
//	if (n > m) {
//		min = m;
//		max = n;
//	}
//	while (min <= max) {
//		std::cout << min << " ";
//		++min;
//	}
//
//	return 0;
//}

#include "Sales_item.h"

//int main() {
//	/*Sales_item book;
//	std::cin >> book;
//	std::cout << book << std::endl;*/
//	Sales_item item1, item2;
//	std::cin >> item1 >> item2;
//	if (item1.isbn() == item2.isbn()) {
//		std::cout << item1 + item2 << std::endl;
//	}
//	else {
//		std::cout << "error: item1.isbn() != item2.isbn()" << std::endl;
//	}
//
//
//	return 0;
//}

//int main() {
//
//	return -1;
//}

int main() {
	Sales_item prev;
	if (std::cin >> prev) {
		Sales_item cur;
		while (std::cin >> cur) {
			if (cur.isbn() == prev.isbn()) {
				prev += cur;
			}
			else {
				std::cout << prev << std::endl;
				prev = cur;
			}
		}
		std::cout << prev << std::endl;
	}
	return 0;
}


