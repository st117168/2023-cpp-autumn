#include <iostream>

int main(int argc(), char* argv[]) {
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	if ((a != 1 && b != 1) || (a == 1 && b == 1)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}