#include <iostream>

int main(int argc(), char* argv[]) {
	int n = 0;
	int a = 0;
	int b = 0;
	int c = 1;
	std::cin >> n;
	n--;
	for (n; n; n--)
	{
		a = b;
		b = c;
		c = a + b;
	}
	std::cout << c;
	return 0;
}
