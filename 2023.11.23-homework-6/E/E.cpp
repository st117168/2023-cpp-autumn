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
    if (n % 2)
    {
        func(n, 1, 2);
    }
    else
    {
        func(n, 1, 3);
    }
    int to = 0;
    to = (n % 2 ? 2 : 3);
    int res = 0;
    res = 5 - to;
    for (int i = n; i > 0; --i)
    {
        func(i - 1, to, res);
        std::swap(to, res);
    }
    return EXIT_SUCCESS;
}
