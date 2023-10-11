#include <iostream>

int main(int argc, char* argv[])
{
    int num = 0;
    std::cin >> num;
    int sum = 0;
    while (num != 0)
    {
        sum += num & 1;
        num = num >> 1;
    }
    std::cout << sum;
    return 0;
}

