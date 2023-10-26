#include "header.h"
#include <iostream>
#include <clocale>
#include <ctime>

void printArray(int* a, int len)
{
    setlocale(LC_ALL, "Russian");
    if (a == nullptr)
	{
		std::cout << "Массив пуст" << std::endl;
	}
	else
    {
        for (int i = 0; i < len; ++i)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}

void expandArray(int*& a, int& len)
{
	int* b = new int[len + 1] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			b[i] = a[i];
		}
		delete[] a;
	}
	a = b;
	++len;
}

void addElement(int*& a, int& len, int element)
{
    expandArray(a, len);
    a[len - 1] = element;
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}

void contractArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* b = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			b[i] = a[i];
		}
		delete[] a;
		a = b;
		--len;
	}
}

int extractElement(int*& a, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = a[index];
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		contractArray(a, len);
	}
	return res;
}

int findIndexMin_AfterIndex(int* a, int len, int index)
{
    if (a != nullptr && indexValid(index, len))
    {
        int minIndex = index;
        for (int i = index; i < len - 1; ++i)
        {
            if (a[i + 1] < a[minIndex])
            {
                minIndex = i + 1;
            }
        }
        return minIndex;
    }
    return -1;

}

void swapElements(int* a, int len, int index1, int index2)
{
    if (a != nullptr)
    {
        int elem1 = a[index1];
        a[index1] = a[index2];
        a[index2] = elem1;
    }
}

void sortArray_min_to_max(int* a, int len)
{
    if (len > 1)
    {
        for (int i = 0; i < len; ++i)
        {
            swapElements(a, len, i, findIndexMin_AfterIndex(a, len, i));
        }
    }
}

void turnArray(int* a, int len)
{
    if (len > 1)
    {
        for (int i = 0; i < len / 2; ++i)
        {
            swapElements(a, len, i, len - i - 1);
        }
    }
}

int firstMaxIndex(int* a, int len)
{
    if (a != nullptr)
    {
        int indexMax = len - 1;
        for (int i = len - 1; i >= 1; --i)
        {
            if (a[i - 1] >= a[indexMax])
            {
                indexMax = i - 1;
            }
        }
        return indexMax;
    }
    return -1;
}

int lastMinIndex(int* a, int len)
{
    if (a != nullptr)
    {
        int indexMin = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            if (a[indexMin] >= a[i + 1])
            {
                indexMin = i + 1;
            }
        }
        return indexMin;
    }
    return -1;
}

void swap_LastMin_FirstMax(int* a, int len)
{
    if (len > 1)
    {
        swapElements(a, len, lastMinIndex(a, len), firstMaxIndex(a, len));
    }
}

void deleteDuplicates(int*& a, int& len)
{
    if (len > 1)
    {
        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (a[i] == a[j])
                {
                    extractElement(a, len, j);
                    j--;
                }
            }
        }
    }
}

void addNRandomElements(int*& a, int& len, int n)
{
    srand(time(0));
    for (int i = 0; i < n; ++i)
    {
        addElement(a, len, rand() % 100);
    }
}
