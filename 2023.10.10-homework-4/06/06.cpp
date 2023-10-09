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

    int maxel = *c;
    int minel = *c;
    for (int i = 1; i < n; ++i)
    {
        if (*(c + i) > maxel)
        {
            maxel = *(c + i);
        }
        if (*(c + i) < minel)
        {
            minel = *(c + i);
        }
    }

    int firstmin = 0;
    int lastmax = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(c + i) == minel)
        {
            firstmin = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (*(c + i) == maxel)
        {
            lastmax = i;

            // перестановка элементов без создания доп. переменной
            i = *(c + firstmin);
            *(c + firstmin) = *(c + lastmax);
            *(c + lastmax) = i;

            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << *(c + i) << " ";
    }

    free(c);
    return 0;
}


