#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#define MAX 1000000

typedef struct timeval Time;

long getSystemTime() {
    Time tv;
    gettimeofday(&tv, NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* arr, int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (*(arr+j) < *(arr+min_idx))
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(arr+min_idx, arr+i);
    }
}

void randomArray(int* arr) {
    for (int i = 0; i < MAX; i++) {
        *(arr+i) = rand() %10000;
    } 
}

void printArray(int* arr) {
    for (int i = 0; i < MAX; i++) {
        printf("%6d", *(arr+i));
    }
    printf("\n");
}

int main() {
    int* arr;
    arr = (int*)malloc(MAX*sizeof(int));
    srand(time(NULL));
    printf("Hello World!\n");

    long startRandom, startSorting, finishSorting, end = 0;

    startRandom = getSystemTime();
    randomArray(arr);

    startSorting = getSystemTime();
    printf("Selection_Sort\nStart Sorting\n");
    selectionSort(arr, MAX);
    finishSorting = getSystemTime();

    printf("Finished sorting!\n");
    
    end = getSystemTime();
    printf("get time start random: %lu\nstart sorting: %lu\nfinish sorting: %lu\nend: %lu\n", startRandom, startSorting,finishSorting,end);
    printf("Bubble_Sort: Sorting time: %lu millisecond\n\n", finishSorting - startSorting);
    return 0;
}