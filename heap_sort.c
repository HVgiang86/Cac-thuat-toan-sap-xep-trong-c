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

void heapify(int* arr, int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && *(arr+left) > *(arr+largest))
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && *(arr+right) >*(arr+largest))
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(arr+i, arr+largest);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int* arr)
{
 
    // Build max heap
    for (int i = MAX / 2 - 1; i >= 0; i--)
 
        heapify(arr, MAX, i);
 
    // Heap sort
    for (int i = MAX - 1; i >= 0; i--) {
 
        swap((arr), arr+i);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
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
    printf("Heap_Sort\nStart Sorting\n");
    heapSort(arr);
    finishSorting = getSystemTime();

    printf("Finished sorting!\n");
    
    end = getSystemTime();
    printf("get time start random: %lu\nstart sorting: %lu\nfinish sorting: %lu\nend: %lu\n", startRandom, startSorting,finishSorting,end);
    printf("Bubble_Sort: Sorting time: %lu millisecond\n", finishSorting - startSorting);
    return 0;
}