#include <iostream>

int main(int argc(), char* argv[]) {
	int n = 0;
	int a60 = 0;
	int a20 = 0;
	int a10 = 0;
	int a5 = 0;
	int a1 = 0;
	std::cin >> n;
	a60 = n / 60;
	a20 = n % 60 / 20;
	a10 = n % 60 % 20 / 10;
	a5 = n % 60 % 20 % 10 / 5;
	a1 = n % 5;
	if (a1 * 15 >= 70) {
		a1 = 0;
		a5++;
	}
	if (a1 * 15 + a5 * 70 >= 125) {
		a1 = 0;
		a5 = 0;
		a10++;
	}
	if (a1 * 15 + a5 * 70 + a10 * 125 >= 230) {
		a1 = 0;
		a5 = 0;
		a10 = 0;
		a20++;
	}
	if (a1 * 15 + a5 * 70 + a10 * 125 + a20 * 230 >= 440) {
		a1 = 0;
		a5 = 0;
		a10 = 0;
		a20 = 0;
		a60++;
	}
	std::cout << a1 << " ";
	std::cout << a5 << " ";
	std::cout << a10 << " ";
	std::cout << a20 << " ";
	std::cout << a60;
	return 0;
}