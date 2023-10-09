#include <iostream>

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

    int countc = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(c + i) > 0)
        {
            countc++;
        }
    }
    std::cout << countc;

    free(c);
    return 0;
}
