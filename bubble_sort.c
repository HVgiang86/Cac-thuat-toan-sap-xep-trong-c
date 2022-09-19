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

void bubbleSort(int* arr) {
    printf("Bubble_Sort\nStart Sorting\n");
    int i, j;
    for (i = 0; i < MAX - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < MAX - i - 1; j++)
            if (*(arr+j) > *(arr+j+1))
                swap((arr+j), (arr+j+1));
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
    bubbleSort(arr);
    finishSorting = getSystemTime();

    printf("Finished sorting!\n");
    
    end = getSystemTime();
    printf("get time start random: %lu\nstart sorting: %lu\nfinish sorting: %lu\nend: %lu\n", startRandom, startSorting,finishSorting,end);
    printf("Bubble_Sort: Sorting time: %lu millisecond\n\n", finishSorting - startSorting);
    return 0;
}