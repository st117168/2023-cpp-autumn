#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int a = 0;
	int b = 0;
	std::cin >> n;
	a = abs(n - 1) / (n - 1);	// знак числа N
	b = 1 + a * (n - 1);	// количество чисел
	std::cout << (1 + n) * b / 2; // сумма чисел
	return 0;
}
