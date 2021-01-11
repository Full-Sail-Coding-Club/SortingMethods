#pragma once
template<typename T>
class Sorter {
public:

    Sorter() {}
    virtual ~Sorter() {}

    virtual void sort(T ar[], int low, int high) = 0;

protected:
    void swap(T* a, T* b) {
        T t = *a;
        *a = *b;
        *b = t;
    }
};