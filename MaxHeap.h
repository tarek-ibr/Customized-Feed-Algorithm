#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // Include this for out_of_range
#include "customVector.h"

using namespace std;

template<typename T>
class MaxHeap {
private:
    vector<T> heap;
    int size;
public:
    MaxHeap(customVector<T>);

    int parent(int);
    int left_child(int x);
    int right_child(int x);
    void swap(T &x, T &y);

    void heapifyup(customVector<T> & arr, int index);
    void heapifydown(customVector<T> & arr, int index);
    void insert(customVector<T> &arr, int value);
    T extract_max(customVector<T> & arr);                       //to remove later i we don't use it
    bool is_a_max_heap(customVector<T> & arr);                 //to remove later i we don't use it
    int min_maxheap(customVector<T> & arr);
    int peaktop(customVector<T> & arr);
    bool isEmpty() const;
    int build_heap(customVector<T> & arr);

    void heap_sort(customVector<T> & arr);
};




#endif // MAX_HEAP_H
