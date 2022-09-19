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

void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = *(arr+i);
        j = i - 1;
  
        /* Move elements of arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && *(arr+j) > key) 
        {
            *(arr+j+1) = *(arr+j);
            j = j - 1;
        }
        *(arr+j+1) = key;
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
    printf("Insertion_Sort\nStart Sorting\n");
    insertionSort(arr, MAX);
    finishSorting = getSystemTime();

    printf("Finished sorting!\n");
    
    end = getSystemTime();
    printf("get time start random: %lu\nstart sorting: %lu\nfinish sorting: %lu\nend: %lu\n", startRandom, startSorting,finishSorting,end);
    printf("Bubble_Sort: Sorting time: %lu millisecond\n\n", finishSorting - startSorting);
    return 0;
}