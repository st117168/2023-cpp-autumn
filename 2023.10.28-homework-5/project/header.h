#pragma once

void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
bool indexValid(int index, int len);
void contractArray(int*& a, int& len);
int extractElement(int*& a, int& len, int index);
int findIndexMin_AfterIndex(int* a, int len, int index);
void swapElements(int* a, int len, int index1, int index2);
void sortArray_min_to_max(int* a, int len);
void turnArray(int* a, int len);
int firstMaxIndex(int* a, int len);
int lastMinIndex(int* a, int len);
void swap_LastMin_FirstMax(int* a, int len);
void deleteDuplicates(int*& a, int& len);
void addNRandomElements(int*& a, int& len, int n);
