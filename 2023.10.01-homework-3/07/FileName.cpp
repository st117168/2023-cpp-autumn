#include <iostream>

int main(int argc(), char* argv[]) {
	int a = 2;
	int n = 0;
	int count = 0;
	std::cin >> n;
	for (count; a < n; count++)
	{
		a *= 2;
	}
	if (n == 0 || n == 1)
	{
		count--;
	}
	std::cout << ++count;
	return 0;
}