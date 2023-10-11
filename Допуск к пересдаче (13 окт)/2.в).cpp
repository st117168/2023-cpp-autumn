#include <iostream>

int main(int argc, char* argv[])
{
    int n = 5;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << (j + i) % n + 1;
        }
        std::cout << std::endl;
    }
    return 0;
}
