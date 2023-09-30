#include <iostream>

int main(int argc(), char* argv[]) {
	int sec = 0;
	int num = 0;
	std::cin >> sec;
	while (sec > 0)
	{
		num++;
		for (int i = num; i > 0 && sec > 0; sec--)
		{
			std::cout << num << " ";
			--i;
		}
	}
	return 0;
}