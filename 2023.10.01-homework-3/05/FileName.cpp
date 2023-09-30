#include <iostream>

int main(int argc(), char* argv[]) {
	int number = 0;
	int numberinversed = 0;
	int count = 0;
	std::cin >> number;
	for (int i = 1; i <= number; i++)
	{
		numberinversed = 0;
		for (int k = i; k; k /= 10)
		{
			numberinversed = numberinversed * 10 + k % 10;
		}
		if (numberinversed == i)
		{
			count++;
		}
	}
	std::cout << count;
	return 0;
}
