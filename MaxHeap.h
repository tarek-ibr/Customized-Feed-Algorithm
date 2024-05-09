#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // Include this for out_of_range

using namespace std;

template<typename T>
class MaxHeap {
private:
    vector<T> heap;
    int size;
public:
    MaxHeap(vector<T>);

    int parent(int);
    int left_child(int x);
    int right_child(int x);
    void swap(T &x, T &y);

    void heapifyup(vector<T> & arr, int index);
    void heapifydown(vector<T> & arr, int index);
    void insert(vector<T> &arr, int value);
    T extract_max(vector<T> & arr);           //to remove later i we dont use it
    bool is_a_max_heap(vector<T> & arr);                 //to remove later i we dont use it
    int min_maxheap(vector<T> & arr);
    int peaktop(vector<T> & arr);
    bool isEmpty() const;
    int build_heap(vector<T> & arr);

    void heap_sort(vector<T> & arr);
};




#endif // MAX_HEAP_H
