#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void mergeSort(int l, int r, int* tab);

void merge(int l, int mid, int r, int* tab);

int main()
{
    srand(time(NULL));
    int tab[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        *(tab + i) = rand() % 101;
    }
    printf("Before merge sort:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", *(tab + i));
    }
    printf("\n\nEvery step taken:\n");
    mergeSort(0, SIZE - 1, tab);
    printf("\nAfter merge sort:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", *(tab + i));
    }
    printf("\n");
    return 0;
}

void mergeSort(int l, int r, int* tab)
{
    if (l < r) //it is only to check whether the size of chunk of the tab is greater than 1
    {
        int mid = (r + l) / 2; //selecting the middle index, for eg. if size = 8 then middle_index = (7 - 0) / 2 + 1 = 3 + 1 = 4
        mergeSort(l, mid, tab);     //splitting the tab in halves
        mergeSort(mid + 1, r, tab);
        merge(l, mid + 1, r, tab);      //merge function that sorts two parts of half-sorted given array
    }
}

void merge(int l, int mid, int r, int* tab)
{
    //necessary
    int i = l;      //left side index
    int j = mid;    //right side index
    int k = 0;      //temporary array index
    int temp_size = r - l + 1; //temporary array size
    int* temp_array = calloc(temp_size, sizeof(int)); //temporary array
    while (i < mid && j < r + 1)    //loop that chooses smaller values and puts them into temporary array
    {
        if (*(tab + i) <= *(tab + j))
        {
            *(temp_array + k) = *(tab + i);
            i++;
            k++;
        }
        else if (*(tab + j) < *(tab + i))
        {
            *(temp_array + k) = *(tab + j);
            j++;
            k++;
        }
    }
    while (i < mid) //loop that fills temporary array with unused values from left chunk
    {
        *(temp_array + k) = *(tab + i);
        i++;
        k++;
    }
    while (j < r + 1) //loop that fills temporary array with unused values from right chunk
    {
        *(temp_array + k) = *(tab + j);
        j++;
        k++;
    }
    for (int a = l, k = 0; a < r + 1; a++, k++) //loop that changes the values in given chunk of original array
    {
        printf("%d ", *(temp_array + k)); //only used to print the effect of sorting
        *(tab + a) = *(temp_array + k);   //filling original array
    }
    printf("\n");
    free(temp_array); //clearing the space of temporary array
}