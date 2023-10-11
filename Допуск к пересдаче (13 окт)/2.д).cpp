#include <iostream>

int main(int argc, char* argv[])
{
    int n = 5;
    for (int i = n / 2; i >= -n / 2; --i)
    {
        for (int j = n / 2; j >= -n / 2; --j)
        {
            std::cout << std::max((n - n / 2) - abs(j), (n - n / 2) - abs(i));
        }
        std::cout << std::endl;
    }
    return 0;
}
