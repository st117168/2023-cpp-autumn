#include <iostream>

int main(int argc(), char* argv[]) {
	int num = 0;
	std::cin >> num;
	while (num % 10 == 0)
	{
		num /= 10;
	}
	while (num != 0)
	{
		std::cout << num % 10;
		num /= 10;
	}
	return 0;
}