#include <iostream>
#include <cstdlib>

int main (int*, char**)
{
    int n = 0;
    std::cin >> n;
    int* c = (int*)malloc(sizeof(int) * n);

    int a = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a;
        *(c + i) = a;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        std::cout << *(c + i) << " ";
    }

    free(c);
    return 0;
}