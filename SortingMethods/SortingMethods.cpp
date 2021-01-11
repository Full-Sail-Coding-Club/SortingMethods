// SortingMethods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* C implementation QuickSort */

#include<stdio.h>
#include "Quicksort.h"

/*Function to print an array */

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
}

// Driver program to test sort methods

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Sorter<int>* s = new Quicksort<int>();
    s->sort(arr, 0, n-1);
    printf("Sorted array: ");
    printArray(arr, n); 
    delete s;
    return 0;
}
