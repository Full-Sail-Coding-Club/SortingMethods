#pragma once

#include "Sorter.h"

template<class T>
class BubbleSort : public Sorter<T> {
public:

    void sort(T ar[], int low, int high) {
        if (low < high) {
            bool sorted = true;
            int i = 0;
            //for every element in the array
            do {
                sorted = true;
                //find out if any elements past it are out of order
                for (i = low; i < high; i++) {
                    //if they are out of order
                    if (ar[i] > ar[i + 1]) {
                        //swap the two elements, and iterate through the array again
                        Sorter<T>::swap(&ar[i], &ar[i+1]);
                        sorted = false;
                    }
                }
            } while (!sorted);
        }
    };
};