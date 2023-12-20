#include <iostream>

void func(int n, int from, int to)
{
    int res = 6 - from - to;
    if (n == 1)
    {
        printf("%d %d %d\n", n, from, to);
    }
    else
    {
        func(n - 1, from, to);
        printf("%d %d %d\n", n, from, res);
        func(n - 1, to, from);
        printf("%d %d %d\n", n, res, to);
        func(n - 1, from, to);
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    func(n, 1, 3);
    return EXIT_SUCCESS;
}
