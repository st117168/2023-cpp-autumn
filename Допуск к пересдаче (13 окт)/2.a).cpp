#include <iostream>

int main(int argc, char* argv[])
{
    int n = 5;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cout << j;
        }
        std::cout << std::endl;
    }
    return 0;
}

