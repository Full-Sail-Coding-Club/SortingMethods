// SortingMethods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* C implementation QuickSort */

#include<stdio.h>

// A utility function to swap two elements 
template <class T>
void swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

#pragma region Quicksort

/*This function takes last element as pivot, places
  the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot)
  to left of pivot and all greater elements to right
  of pivot */
template <class T>
int partition(T arr[], int low, int high) {
    int pivot = arr[high];      //pivot
    int i = (low - 1);          //index of smaller element
    for (int j = low; j <= high - 1; j++) {
        //if current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; //increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/*
The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
template <class T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        //pi is petitioning index, arr[p] is now at right place.
        int pi = partition(arr, low, high);

        //separately sort elements before partition and after partition.
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

#pragma endregion

/*Function to print an array */

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
}

// Driver program to test above functions 

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
