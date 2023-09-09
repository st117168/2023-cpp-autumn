#include <iostream>

int main(int argc, char* argv[]) {
	int U = 0;
	int T = 0;
	int a = 0;
	int S = 0;
	std::cin >> U;
	std::cin >> T;
	a = U * T % 109;
	S = (a + 109) % 109 + 1;
	std::cout << S;
	return 0;
}
