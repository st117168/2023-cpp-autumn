#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    int s = (n > 0 ? 1 : 0);

    if (n == 0)
    {
        std::cout << 0 << " " << 0;
    }
    else if (s)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << i << " ";
        }
        for (int i = n; i >= 0; i--)
        {
            std::cout << i << " ";
        }
    }
    else
    {
        for (int i = 0; i > n; i--)
        {
            std::cout << i << " ";
        }
        for (int i = n; i <= 0; i++)
        {
            std::cout << i << " ";
        }
    }
    return 0;
}
