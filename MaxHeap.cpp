//
// Created by tarek on 5/9/2024.
//

#include "MaxHeap.h"

MaxHeap::MaxHeap(){
    heap = customVector<maxHeapNode>();
}

MaxHeap::MaxHeap(customVector<maxHeapNode> v) :heap(v){}

int MaxHeap::parent(int x)
{
    return (x+1)/2 - 1;
}

int MaxHeap::left_child(int x)
{
    return 2*x + 1;
}

int MaxHeap::right_child(int x) {
    return 2*x + 2;
}

void MaxHeap::swap(maxHeapNode &x, maxHeapNode &y) {
    maxHeapNode temp = x;
    x = y;
    y = temp;
}


void MaxHeap::heapifyup(size_t index)
{
    while (index != 0) {
        if (heap[index].relevancepoints>heap[parent(index)].relevancepoints) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
        else
            break;

    }
}

void MaxHeap::heapifydown(size_t index) {
    while (left_child(index) < heap.getcurrent() && (heap[index].relevancepoints > heap[left_child(index)].relevancepoints)
           || (right_child(index) < heap.getcurrent() && heap[index].relevancepoints > heap[right_child(index)].relevancepoints))
    {
        int min = index;
        if (heap[min].relevancepoints > heap[left_child(index)].relevancepoints)
            min = left_child(index);
        else if ((heap[min].relevancepoints > heap[right_child(index)].relevancepoints) && right_child(index) < heap.getcurrent())
            min = right_child(index);
        else if (min == index)
            break;
        swap(heap[min], heap[index]);
        index = min;
    }
}


void MaxHeap::insert(maxHeapNode value) {
    heap.push(value);

    heapifyup(heap.getcurrent() - 1);
}

maxHeapNode MaxHeap::extract_max() {
    maxHeapNode value = heap[0];

    swap(heap[0], heap[heap.getcurrent()-1]);
    heap.setcurrent(heap.getcurrent()-1);
    heapifydown(0);

    return value;
}

bool MaxHeap::is_a_max_heap() {
    int size = heap.getcurrent();

    for(int i=size/2 - 1;i>=0;i--){
        if (right_child(i)<size && heap[right_child(i)].relevancepoints>heap[i].relevancepoints)
            return false;
        if (left_child(i)<size && heap[left_child(i)].relevancepoints>heap[i].relevancepoints)
            return false;

    }
    return true;
}

maxHeapNode MaxHeap::min_maxheap() {
    int size = heap.getcurrent();
    maxHeapNode min =heap[0];
    for(int i=size/2 ;i<size;i++)
        if(heap[i].relevancepoints<min.relevancepoints)
            min = heap[i];
    return min;
}

maxHeapNode MaxHeap::peaktop() {
    return heap[0];
}

bool MaxHeap::isEmpty() const {
    return heap.empty();
}

void MaxHeap::build_heap() {
    for (int i = heap.getcurrent()/2; i >= 0; i--)
    {
        heapifydown(i);
    }
}

void MaxHeap::heap_sort() {
    build_heap();

    int count = heap.getcurrent()-1;
    while (count > 0)
    {
        swap(heap[0], heap[count]);

        heapifydown( 0);
        count--;
    }
}

