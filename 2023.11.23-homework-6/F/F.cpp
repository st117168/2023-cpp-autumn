#include<iostream>

void func(int n, int from = 1, int to = 3)
{
    int res = 6 - from - to;
    if (n == 1)
    {
        printf("%d %d %d\n", 1, from, to);;
    }
    else
    {
        func(n - 1, from, to);
        if (n > 2)
        {
            func(n - 2, to, res);
        }
        printf("%d %d %d\n", 0, from, to);
        if (n > 2)
        {
            func(n - 2, res, from);
        }
        func(n - 1, from, to);
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    func(n);
    return EXIT_SUCCESS;
}

