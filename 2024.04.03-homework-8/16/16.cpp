#include <iostream>

class CTree{
public:
    CTree();
    CTree(int a, int b, int n);
    ~CTree();
    void ReadTree(int n, std::istream& stream);
    void task();
private:
    void init();
    void dispose();
    int* _tree;
    int _a;
    int _b;
    int _n;
};

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    std::cin >> n >> a >> b;
    CTree t(a, b, n);
    t.ReadTree(n, std::cin);
    t.task();
    return 0;
}

CTree::CTree()
    : _a(0), _b(0), _tree(nullptr), _n(0){}

CTree::CTree(int a, int b, int n)
    : _a(a), _b(b), _tree(nullptr), _n(n)
{
    init();
}

CTree::~CTree()
{
    dispose();
}

void CTree::init()
{
    if (_n == 0)
    {
        return;
    }
    _tree = new int[_n];
}

void CTree::dispose()
{
    delete[] _tree;
    _tree = nullptr;
}

void CTree::ReadTree(int n, std::istream& stream)
{
    _n = n;
    init();
    for (int i = 1; i < _n; i++)
    {
        stream >> _tree[i];
    }
}

void CTree::task()
{
    while (_a != _b)
    {
        if (_a > _b)
        {
            _a = _tree[_a - 1];
        }
        else
        {
            _b = _tree[_b - 1];
        }
    }
    std::cout << _a;
}
