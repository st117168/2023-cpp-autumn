#include <iostream>

int main(int argc(), char* argv[]) {
	int a = 0;
	int x = 0;
	int i = 1;
	std::cin >> x;
	for (i; i * i < x; i++)
	{
		if (x % i == 0)
		{
			a += 2;
		}
	}
	if (i * i == x)
	{
		a++;
	}
	std::cout << a;
	return 0;
}