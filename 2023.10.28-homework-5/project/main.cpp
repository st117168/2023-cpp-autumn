#include "header.h"
#include <iostream>
#include <clocale>

void printMenu();

int main(int argc(), char* argv[])
{
    bool printing = false;
    int len = 5;
    int* a = new int[5] {1, 2, 3, 4, 5};
	bool exit = false;
	setlocale(LC_ALL, "Russian");
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			if (printing)
            {
                printArray(a, len);
            }
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
                case 0:
                {
                    exit = true;
                    break;
                }
                case 1:
                {
                    printArray(a, len);
                    system("pause");
                    break;
                }
                case 2:
                {
                    int element = 0;
                    std::cout << "������� ������� ��� ����������: ";
                    std::cin >> element;
                    addElement(a, len, element);
                    break;
                }
                case 3:
                {
                    int index = 0;
                    std::cout << "������� ������ ��� ��������: ";
                    std::cin >> index;
                    std::cout << "�������: " << extractElement(a, len, index) << std::endl;
                    system("pause");
                    break;
                }
                case 4:
                {
                    sortArray_min_to_max(a, len);
                    break;
                }
                case 5:
                {
                    turnArray(a, len);
                    break;
                }
                case 6:
                {
                    std::cout << "�������� ������:" << std::endl;
                    printArray(a, len);
                    swap_LastMin_FirstMax(a, len);
                    std::cout << "����������� ������:" << std::endl;
                    printArray(a, len);
                    system("pause");
                    break;
                }
                case 7:
                {
                    deleteDuplicates(a, len);
                    break;
                }
                case 8:
                {
                    int n = 0;
                    std::cout << "������� ����� n: ";
                    std::cin >> n;
                    addNRandomElements(a, len, n);
                    break;
                }
                case 9:
                {
                    printing = !printing;
                    break;
                }
                default:
                {
                    std::cout << "����������� �������" << std::endl;
                    break;
                }
			}
		}
	}
	delete[] a;
    return 0;
}

void printMenu()
{
	std::cout << "0 - ����� �� ���������" << std::endl;
	std::cout << "1 - ������� ������" << std::endl;
	std::cout << "2 - �������� ������� � ������" << std::endl;
	std::cout << "3 - ������� ������� �� �������" << std::endl;
	std::cout << "4 - ������������� ������ �� �����������" << std::endl;
	std::cout << "5 - ���������� ������" << std::endl;
	std::cout << "6 - �������� ������� ������ ������������ � ��������� ����������� ������� �������" << std::endl;
	std::cout << "7 - ������� �� ������� ��� ���������" << std::endl;
	std::cout << "8 - �������� � ������ n ��������� (�� 0 �� 99) ���������" << std::endl;
	std::cout << "9 - ���/���� ���������� ����� �������" << std::endl;
}
