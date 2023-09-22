#ifndef SORT_ALGO_H_INCLUDED
#define SORT_ALGO_H_INCLUDED

typedef enum Sort_Status
{
    SortOk,NoSort
}sort_s;

void swap(int*, int*);

void _SelectionSort(int* ,int);

void _BubbleSort(int* , int);

#endif // SORT_ALGO_H_INCLUDED
