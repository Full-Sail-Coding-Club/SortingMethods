#pragma once

#include "Sorter.h"

template<class T>
class Quicksort : public Sorter<T> {
public:

    void sort(T ar[], int low, int high);

private:
    int partition(T arr[], int low, int high);
    void quickSort(T arr[], int low, int high);
};
