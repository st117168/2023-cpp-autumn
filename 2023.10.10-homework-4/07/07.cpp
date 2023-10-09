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

    int wrongnumbers = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(c + i) <= 0)
        {
            *(c + i) = 0;
            wrongnumbers++;
        }
    }

    int* d = (int*)malloc(sizeof(int) * (n - wrongnumbers));
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(c + i) != 0)
        {
            *(d + k) = *(c + i);
            k++;
        }
        if (k == n - wrongnumbers)
        {
            break;
        }
    }
    free(c);
    n -= wrongnumbers;

    for (int i = 0; i < n; ++i)
    {
        std::cout << *(d + i) << " ";
    }

    free(d);
    return 0;
}


