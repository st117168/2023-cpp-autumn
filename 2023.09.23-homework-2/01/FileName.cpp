#include <iostream>

int main(int argc(), char* argv[]) {
	int a = 0;
	std::cin >> a;
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}