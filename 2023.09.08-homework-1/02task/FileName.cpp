#include <iostream>

int main(int argc, char* argv[]) {
	int N = 0;
	int a = 0;
	int b = 0;
	std::cin >> N;
	a = abs(N - 1) / (N - 1);	// знак числа N
	b = 1 + a * (N - 1);	// количество чисел
	std::cout << (1 + N) * b / 2; // сумма чисел
	return 0;
}
