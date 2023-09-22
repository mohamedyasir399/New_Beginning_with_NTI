#include "search_algo.h"

int _LinearSearch(int *arr, int size, int num)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i] == num)
        {
            printf("  %d     %d\n",arr[i],i);
            return i;
        }
    }
    printf("not found");
    return -1;
}

int _BinarySearch(int *arr, int size, int num)
{
    int midIndex, LowerIndex =0, higherIndex =size-1;
    while(LowerIndex <=higherIndex)
    {
        midIndex =(LowerIndex + higherIndex)/2;
        if(arr[midIndex] == num)
        {
            return midIndex;
        }
        else if(arr[midIndex] > num)
        {
            higherIndex = midIndex-1;
        }
        else if(arr[midIndex] < num)
        {
            LowerIndex = midIndex +1;
        }
    }
    printf("not found");
    return -1;
}
