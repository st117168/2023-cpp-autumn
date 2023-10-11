#include <iostream>

int main(int argc, char* argv[])
{
    int num = 0;
    std::cin >> num;
    int n = num;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    int nummax = n - (n >> 1);
    int nummin = num & (~num + 1);
    for (int i = nummin << 1; i < nummax; i <<= 1)
    {
        num ^= i;
    }
    std::cout << num;
    return 0;
}

