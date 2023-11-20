#include<iostream>
#include<algorithm>
#include<ctime>

void initRandomArray(int len, int mn, int mx, int*& a);

void print(int* a, int len);
void swap(int& a, int& b);
bool isSorted(int * a, int len);
void mix(int* a, int len);

void bubbleSort(int* a, int len);
void insertionSort(int* a, int len);
void selectionSort(int* a, int len);
void countSort(int* a, int len);
void gnomeSort(int* a, int len);
void monkeySort(int* a, int len);

int main(int argc, char* argv[])
{
	srand(time(0));
	int n = 10;
	int* a = nullptr;
	std::cout << "init. random array" << std::endl;
	initRandomArray(n, 0, 9, a);
        print(a, n);
	{
		std::cout << "bubble sort" << std::endl;
		mix(a, n);
		print(a, n);
		bubbleSort(a, n);
		print(a, n);
	}
	{
        std::cout << "insertion sort" << std::endl;
		mix(a, n);
		print(a, n);
		insertionSort(a, n);
		print(a, n);
	}
	{
		std::cout << "selection sort" << std::endl;
		mix(a, n);
		print(a, n);
		selectionSort(a, n);
		print(a, n);
	}
	{
		std::cout << "count sort" << std::endl;
		mix(a, n);
		print(a, n);
		countSort(a, n);
		print(a, n);
	}
	{
		std::cout << "gnome sort" << std::endl;
		mix(a, n);
		print(a, n);
		gnomeSort(a, n);
		print(a, n);
	}
        {
		std::cout << "monkey sort" << std::endl;
		mix(a, n);
		print(a, n);
		monkeySort(a, n);
		print(a, n);
	}
	return EXIT_SUCCESS;
}

void initRandomArray(int len, int mn, int mx, int*& a)
{
	int* b = new int[len] { 0 };
	for (int i = 0; i < len; ++i)
	{
		b[i] = rand() % (mx - mn + 1) + mn;
	}
	a = b;
	b = nullptr;
}

void print(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void mix(int * a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		swap(a[i], a[rand() % n]);
	}
}

void bubbleSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void selectionSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		int minInd = i;
		for (int j = i + 1; j < len; ++j)
		{
			minInd = (a[minInd] <= a[j] ? minInd : j);
		}
		swap(a[i], a[minInd]);
	}
}

bool isSorted(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

void monkeySort(int* a, int len)
{
	while (!isSorted(a, len))
	{
		mix(a, len);
	}
}

void insertionSort(int* a, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int t = i;
		while (t > 0 && a[t] < a[t - 1])
		{
			swap(a[t], a[t - 1]);
			--t;
		}
	}
}

void countSort(int* a, int len)
{
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < len; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    int *c = new int[max + 1 - min]{ 0 };
    for (int i = 0; i < len; i++)
    {
        c[a[i] - min] = c[a[i] - min] + 1;
    }
    int i = 0;
    for (int j = min; j < max + 1; j++)
    {
        while (c[j-min] != 0)
        {
            a[i] = j;
            c[j-min]--;
            i++;
        }
    }
}

void gnomeSort(int* a, int len)
{
    int i = 1;
    int j = 2;
    while (i < len)
    {
        if (a[i - 1] < a[i])
        {
            i = j;
            j++;
        }
        else
        {
            swap(a[i - 1], a[i]);
            i--;
            if (i == 0)
            {
                i = j;
                j++;
            }
        }
    }
}
