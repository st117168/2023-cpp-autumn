#include <iostream>

int main(int argc(), char* argv[]) {
	int a = 0;
	int b = 0;
	int a1 = 0;
	int b1 = 0;
	int n = 0;
	int sw = 1;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	a1 = a;
	b1 = b;
	while (a1 != 0 && b1 != 0)
	{
		if (a1 < b1)
		{
			std::swap(a1, b1);
		}
		a1 %= b1;
	}
	if (n % b1 != 0 || n > a && n > b)
	{
		std::cout << "Impossible";
		return 0;
	}
	a1 = 0;
	b1 = 0;
	if (a > b)
	{
		std::swap(a, b);
		sw = 0;
	}
	while (n != a1 && n != b1)
	{
		b1 += a;
		if (b1 > b)
		{
			a1 += b1 % b;
			b1 = a1;
			a1 = 0;
			if (sw)
			{
				std::cout << ">A" << std::endl;
				std::cout << "A>B" << std::endl;
			}
			else
			{
				std::cout << ">B" << std::endl;
				std::cout << "B>A" << std::endl;
			}
			if (n != b1)
			{
				if (sw)
				{
					std::cout << "B>" << std::endl;
					std::cout << "A>B" << std::endl;
				}
				else
				{
					std::cout << "A>" << std::endl;
					std::cout << "B>A" << std::endl;
				}
			}
		}
		else
		{
			if (sw)
			{
				std::cout << ">A" << std::endl;
				std::cout << "A>B" << std::endl;
			}
			else
			{
				std::cout << ">B" << std::endl;
				std::cout << "B>A" << std::endl;
			}
		}
	}
	return 0;
}