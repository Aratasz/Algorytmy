/*
Binary search simple algorithm

To compile:
gcc -ansi -pedantic -W -Wall BinarySearch.c -lm -o BinarySearch
To run:
./BinarySearch
*/
#include "stdio.h"
#include "math.h"
#define MAX 20


int binarySearch(int *sortedTable, int num)
{
    int lowerBound = 0;
    int upperBound = MAX - 1;
    int midPoint = -1;
    int guess = 0;
    int count = 0;

    while(lowerBound <= upperBound)
    {
        midPoint = floor((lowerBound + upperBound)/2);
        guess = sortedTable[midPoint];
        if (guess == num)
        {
            printf("Count is: %d\n", count);
            return guess;
        }
        else if (guess > num)
        {
            upperBound = midPoint -1;
        }
        else
        {
            lowerBound = midPoint + 1;
        }
        count++;
        printf("The guess is: %d\n", guess);
    }
    printf("Count is: %d\n", count);
}

int main()
{
    printf("====>Binary Search<====\n");
    int array[MAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int num = 4;
    binarySearch(array, num);    
}

