#include <stdio.h>
#include "insertionSort.h"
#define len 50
int main()
{
    int arr[len];
    int* p=arr;
    int n;
    for (size_t i = 0; i < len; i++)
    {
        scanf("%d",&n);
        *(arr+i)=n;
    }//for
    insertion_sort(p,len);
    print(arr,len); 
    return 0;
}//main