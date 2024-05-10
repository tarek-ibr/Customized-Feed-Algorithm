//
// Created by tarek on 5/9/2024.
//

#include "MaxHeap.h"

template<typename T>
MaxHeap<T>::MaxHeap(customVector<T> v) :heap(v), size(v.size()){}

template<typename T>
int MaxHeap<T>::parent(int x)
{
    return (x+1)/2 - 1;
}

template<typename T>
int MaxHeap<T>::left_child(int x)
{
    return 2*x + 1;
}

template<typename T>
int MaxHeap<T>::right_child(int x) {
    return 2*x + 2;
}

template<typename T>
void MaxHeap<T>::swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}


template<class T>
void MaxHeap<T>::heapifyup(customVector<T> & arr, int index)
{
    while (index != 0) {
        if (arr[index]>arr[parent(index)]) {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
        else
            break;

    }
}

template<typename T>
void MaxHeap<T>::heapifydown(customVector<T> &arr, int index) {
    while (left_child(index) < size && (arr[index] > arr[left_child(index)])
           || (right_child(index) < size && arr[index] > arr[right_child(index)]))
    {
        int min = index;
        if (arr[min] > arr[left_child(index)])
            min = left_child(index);
        if ((arr[min] > arr[right_child(index)]) && right_child(index) < size)
            min = right_child(index);
        if (min == index)
            break;
        swap(arr[min], arr[index]);
        index = min;
    }
}


template<typename T>
void MaxHeap<T>::insert(customVector<T> &arr, int value) {
    if (arr.capacity() > (unsigned int)size)
        arr[size] = value;
    else
        arr.push_back(value);
    size++;
    shiftup(arr, size - 1);
}

template<typename T>
T MaxHeap<T>::extract_max(customVector<T> &arr) {
    T value = arr[0];

    swap(arr[0], arr[size-1]);
    size--;
    shiftdown(arr, 0, size);

    return value;
}

template<typename T>
bool MaxHeap<T>::is_a_max_heap(customVector<T> &arr) {
    int size = arr.size();

    for(int i=size/2 - 1;i>=0;i--){
        if (right_child(i)<size && arr[right_child(i)]>arr[i])
            return false;
        if (left_child(i)<size && arr[left_child(i)]>arr[i])
            return false;

    }
    return true;
}

template<typename T>
int MaxHeap<T>::min_maxheap(customVector<T> &arr) {
    int size = arr.size();
    int min =arr[0];
    for(int i=size/2 ;i<size;i++)
        if(arr[i]<min)
            min = arr[i];
    return min;
}

template<typename T>
int MaxHeap<T>::peaktop(customVector<T> &arr) {
    return arr[0];
}

template<typename T>
bool MaxHeap<T>::isEmpty() const {
    return heap.empty();
}

template<typename T>
int MaxHeap<T>::build_heap(customVector<T> &arr) {
    int swaps = 0;
    for (int i = size/2; i >= 0; i--)
    {
        swaps += shiftdown_assignment(arr, i, size);
    }
    return swaps;
}

template<typename T>
void MaxHeap<T>::heap_sort(customVector<T> &arr) {
    int swaps = 0;
    swaps += build_heap(arr, arr.size());

    int count = arr.size()-1;
    while (count > 0)
    {
        swap(arr[0], arr[count]);

        swaps++;
        swaps += shiftdown_assignment(arr, 0, count);
        count--;
    }
    cout << swaps << endl;
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

