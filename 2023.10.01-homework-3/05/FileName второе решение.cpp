#include <iostream>

int main(int argc(), char* argv[]) {
	int number = 0;
	int count = 0;
	int c = 1;
	std::cin >> number;
	for (int i = 1; i <= number; i++)
	{
		c = 100000;
		while (i / c == 0)
		{
			c /= 10;
		}
		switch (c)
		{
		case(1):
			count++;
			break;
		case(10):
			if (i / 10 == i % 10)
			{
				count++;
				break;
			}
			break;
		case(100):
			if (i / 100 == i % 10)
			{
				count++;
				break;
			}
			break;
		case(1000):
			if (i / 1000 == i % 10 && i % 1000 / 100 == i % 100 / 10)
			{
				count++;
				break;
			}
			break;
		case(10000):
			if (i / 10000 == i % 10 && i % 10000 / 1000 == i % 100 / 10)
			{
				count++;
				break;
			}
			break;
		case(100000):
			if (i / 100000 == i % 10 && i % 100000 / 10000 == i % 100 / 10 && i % 10000 / 1000 == i % 1000 / 100)
			{
				count++;
				break;
			}
			break;
		}
	}
	std::cout << count;
	return 0;
}
