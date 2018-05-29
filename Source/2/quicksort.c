/*
Quicksort simple algorithm

To compile:
gcc -std=c11 -ansi -pedantic -W -Wall quicksort.c -lm -o quicksort
To run:
./quicksort
*/
#include "stdio.h"
#include "math.h"
#define MAX 20

void printArray(int *array, int size)
{
    int i;
    for (i=0; i<size;i++)
    {
        if (i == 0) {printf("\n[");}
        if (i < size-1)
        {
            printf("%d, ", array[i]);
        }
        else
        {
            printf("%d", array[i]);
        }
    }
    printf("]\n");
}
void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int replace(int *array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    static int debugCountOfSwaps = 0;
    static int debugCountOfNotSwaps = 0;
    int j;
    for (j = low; j <= high-1; j++)
    {
        if (array[j] <= pivot)
        {
            printf("Swapping:  %d and %d\n", array[i], array[j]);
            debugCountOfSwaps++;
            i++;
            swap(&array[i], &array[j]);
        }
        debugCountOfNotSwaps++;
        printf("Not swapping\n");
    }
    swap(&array[i+1], &array[high]);
    printf("debugCountOfSwaps: %d\ndebugCountOfNotSwaps: %d\n", debugCountOfSwaps, debugCountOfNotSwaps);
    return (i+1);
}


int quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = replace(array, low, high);

        quicksort(array, low, pi-1);
        quicksort(array, pi+1, high);
    }
}


int main()
{
    int arr[MAX]= {11,1,2,3,4,5,20,6,7,8,9,12,13,14,15,16,10,17,18,19};
    printf("QUICKSORT ALGORITHM\n");
    printArray(arr, MAX);
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    printf("sorted!\n");
    printArray(arr, MAX);

}