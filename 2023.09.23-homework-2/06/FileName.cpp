#include <iostream>

int main(int argc(), char* argv[]) {
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	if (2 * n % k == 0) {
		std::cout << 2 * n / k * m;
	}
	else if (k >= n) {
		std::cout << 2 * m;
	}
	else {
		std::cout << 2 * n / k * m + m;
	}
	return 0;
}