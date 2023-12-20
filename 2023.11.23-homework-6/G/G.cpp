#include<iostream>

int n[4] { 0 };
int** d = new int* [4] {nullptr, new int[10] { 0 }, new int[10] { 0 }, new int[10] { 0 }};

int top(int k)
{
    if (n[k] == 0)
    {
        return 11;
    }
    return d[k][n[k] - 1];
}

void shift(int from = 1, int to = 3)
{
    std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
    d[to][n[to]++] = d[from][--n[from]];
}

void hanoy(int count, int from = 1, int to = 3)
{
    if (count == 0)
    {
        return;
    }
    int res = 6 - from - to;
    hanoy(count - 1, from, res);
    shift(from, to);
    hanoy(count - 1, res, to);
}

int lowerDisksCount(int disk, int k)
{
    int c = 0;
    for (int i = 0; i < n[disk]; ++i)
    {
        if (d[disk][i] >= k)
        {
            ++c;
        }
    }
    return n[disk] - c;
}

void sort()
{
    int b = 3;
    int c = 2;
    int k = 0;
    while (n[1] != 0)
    {
        k = top(1);
        while (top(c) < k)
        {
            hanoy(lowerDisksCount(b, top(c)), b, c);
            std::swap(b, c);
        }
        shift(1, c);
    }
    while (n[c] != 0)
    {
        if (top(1) >= top(c))
        {
            hanoy(lowerDisksCount(b, top(c)), b, c);
        }
        std::swap(b, c);
    }
}

int main(int argc, char* argv[])
{
    std::cin >> n[1];
    for (int i = n[1] - 1; i >= 0; --i)
    {
        std::cin >> d[1][i];
    }
    sort();
    return EXIT_SUCCESS;
}
