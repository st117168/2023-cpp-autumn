#include <iostream>

int main(int argc(), char* argv[]) {
	int a = 0;
	int b = 0;
	std::cin >> a;
	b = a % 10;
	if (a % 100 < 10 || a % 100 > 20) {
		if (b == 1) {
			std::cout << a << " bochka";
		}
		else if (2 <= b && b <= 4) {
			std::cout << a << " bochki";
		}
		else {
			std::cout << a << " bochek";
		}
	}
	else {
		std::cout << a << " bochek";
	}
	return 0;
}