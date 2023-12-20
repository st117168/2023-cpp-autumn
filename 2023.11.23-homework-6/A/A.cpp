#include <iostream>

void func(int n, int from, int to)
{
    if (n <= 0)
    {
    return;
    }
    int res = 6 - from - to;
    func(n - 1, from, res);
    printf("%d %d %d\n", n, from, to);
    func(n - 1, res, to);
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    func(n, 1, 3);
    return EXIT_SUCCESS;
}
