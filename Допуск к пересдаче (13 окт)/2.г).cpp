#include <iostream>

int main(int argc, char* argv[])
{
    int n = 5;
    for (int i = n; i > 0; --i)
    {
        for (int j = n; j > 0; --j)
        {
            std::cout << j + i - 1;
        }
        std::cout << std::endl;
    }
    return 0;
}
