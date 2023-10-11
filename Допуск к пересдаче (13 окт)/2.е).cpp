#include <iostream>

int main(int argc, char* argv[])
{
    int n = 5;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = n; j >= 1; --j)
        {
            std::cout << abs(i % 2 * (n + 1) - j);
        }
        std::cout << std::endl;
    }
    return 0;
}
