// SortingMethods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* C implementation QuickSort */

#include<stdio.h>
#include "Quicksort.h"
#include "Quicksort.cpp"

/*Function to print an array */

template<class T>
void printArray(T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
}

/*
* main required.
* 
*/

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Sorter<int>* s = new Quicksort<int>();
    printf("Unsorted array: ");
    printArray(arr, n);
    s->sort(arr, 0, 3);
    printf("\nSemiSorted array: ");
    printArray(arr, n);
    s->sort(arr, 0, n - 1);
    printf("\nSorted array: ");
    printArray(arr, n);
    delete s;
    return 0;
}
