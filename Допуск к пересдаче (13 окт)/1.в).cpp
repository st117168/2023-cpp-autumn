#include <iostream>

int main(int argc, char* argv[])
{
    short n1 = 0;
    std::cin >> n1;
    short n2 = 0;
    std::cin >> n2;

    short sum = 0;
    short a = 1;

    bool k = 0;
    bool s = 0;
    bool p = 0;

    while (n1 != 0 || n2 != 0)
    {
        k = (n1 & 1) ^ (n2 & 1);
        s = k ^ p;
        p = ((n1 & 1) & (n2 & 1)) | (k & p);
        sum |= (s ? a : 0);
        n1 >>= 1;
        n2 >>= 1;
        a <<= 1;
    }
    sum |= (p ? a : 0);
    std::cout << sum;
    return 0;
}

