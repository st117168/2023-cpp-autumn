#include <iostream>

int main(int argc, char* argv[]) {
	int u = 0;
	int t = 0;
	int a = 0;
	int s = 0;
	std::cin >> u;
	std::cin >> t;
	a = u * t % 109;
	s = (a + 109) % 109 + 1;
	std::cout << s;
	return 0;
}
