#include <iostream>

int main(int argc(), char* arv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a > b) {
		std::swap(a, b);
	}
	if (a > c) {
		std::swap(a, c);
	}
	if (b > c) {
		std::swap(b, c);
	}
	std::cout << a << " ";
	std::cout << b << " ";
	std::cout << c << " ";
	return 0;
}