#include "sort_algo.h"

void swap(int *x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void _SelectionSort(int *arr,int size)
{
    int smallest_index;
    for(int i=0;i<(size-1);i++)
    {
        smallest_index = i;
        for(int j= i+1;j<size;j++)
        {
            if(arr[j] < arr[smallest_index])
                smallest_index = j;
        }
        if(i != smallest_index)
            swap(arr+i, arr+smallest_index);
    }
}

void _BubbleSort(int *arr, int size)
{
    sort_s Swap_Flag = NoSort;
    for(int i=0;i<(size-1);i++)
    {
        Swap_Flag =NoSort;
        for(int j=0;j<(size-i-1);j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr+j, arr+j+1);
                Swap_Flag = SortOk;
            }
        }
        if(Swap_Flag)   ///if it noSort break cause it has been sorted
            break;
    }
}
