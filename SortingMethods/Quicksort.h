#pragma once

#include "Sorter.h"

template<class T>
class Quicksort : public Sorter<T> {
public:

    void sort(T ar[], int low, int high) {
        quickSort(ar, low, high);
    }

private:
    /*This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
    //template <class T>
    int partition(T arr[], int low, int high) {
        int pivot = arr[high];      //pivot
        int i = (low - 1);          //index of smaller element
        for (int j = low; j <= high - 1; j++) {
            //if current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; //increment index of smaller element
                Sorter<T>::swap(&arr[i], &arr[j]);
            }
        }
        Sorter<T>::swap(&arr[i + 1], &arr[high]);
        return i + 1;
    }

    /*
    The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low  --> Starting index,
    high  --> Ending index */
    //template <class T>
    void quickSort(T arr[], int low, int high) {
        if (low < high) {
            //pi is petitioning index, arr[p] is now at right place.
            int pi = partition(arr, low, high);

            //separately sort elements before partition and after partition.
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};
