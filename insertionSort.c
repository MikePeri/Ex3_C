#include "insertionSort.h"
#include <stdio.h>

/**
 * Input:Array pointer and number (i)
 * Output:This function will move the i elements in the array to the right.
*/
void shift_element(int* arr, int i)
{
    int j,next;
    for (j = 0; j <i; j++)
    {
        next=*(arr+j+1);
        *(arr+j+1)=*arr;
        *arr=next;
    }//for 
}//shift ellement
void insertion_sort(int* arr , int len)
{
   int i,j;//indication of steps
    for (j = 1; j < len; j++)
    {
            int counter=0;//How many shifts we need
            i=j-1;
            int value=*(arr+j);
            while(i>=0 && value<*(arr+i))
            {
                counter++;
                i--;
            }//while
            shift_element(arr+i+1,counter);
        }//for
    }//insertion_sort
void print(int* arr,int i)
{
    int j;
    for (j = 0; j < i-1; j++)
    {
        printf("%d,", *(arr+j));
    }//for
    printf("%d", *(arr+j));
    printf("\n");
}//print
