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

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int* arr, int low, int high) 
{ 
    int pivot = *(arr+high); // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (*(arr+j) < pivot) 
        { 
            i++; // increment index of smaller element 
            swap((arr+i),(arr+j)); 
        } 
    } 
    swap((arr+i+1), (arr+high)); 
    return (i + 1); 
} 

void quickSort(int* arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void randomArray(int* arr) {
    for (int i = 0; i < MAX; i++) {
        *(arr+i) = rand() %100000;
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
    //printArray(arr);

    startSorting = getSystemTime();
    printf("Quick_Sort\nStart Sorting!\n");
    quickSort(arr,0,MAX-1);
    finishSorting = getSystemTime();

    printf("Finished sorting!\n");
    
    
    end = getSystemTime();
    printf("get time start random: %lu\nstart sorting: %lu\nfinish sorting: %lu\nend: %lu\n", startRandom, startSorting,finishSorting,end);
    printf("Quick_Sort: Sorting time: %lu millisecond\n", finishSorting - startSorting);
    return 0;
}