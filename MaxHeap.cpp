//
// Created by tarek on 5/9/2024.
//

#include "MaxHeap.h"

// Constructor initializes an empty MaxHeap
MaxHeap::MaxHeap(){
    heap = customVector<maxHeapNode>();
}

// Constructor initializes a MaxHeap with a given vector
MaxHeap::MaxHeap(customVector<maxHeapNode> v) :heap(v){}

// Returns the parent index of a given node index
// Time Complexity: O(1)
// Space Complexity: O(1)
int MaxHeap::parent(int x) {
    return (x+1)/2 - 1;
}

// Returns the left child index of a given node index
// Time Complexity: O(1)
// Space Complexity: O(1)
int MaxHeap::left_child(int x) {
    return 2*x + 1;
}

// Returns the right child index of a given node index
// Time Complexity: O(1)
// Space Complexity: O(1)
int MaxHeap::right_child(int x) {
    return 2*x + 2;
}

// Swaps two nodes
// Time Complexity: O(1)
// Space Complexity: O(1)
void MaxHeap::swap(maxHeapNode &x, maxHeapNode &y) {
    maxHeapNode temp = x;
    x = y;
    y = temp;
}

// Restores the heap property going up from a given index
// Time Complexity: O(log n) in the worst case, where n is the number of nodes
// Space Complexity: O(1)
void MaxHeap::heapifyup(size_t index) {
    while (index != 0) {
        if (heap[index].relevancepoints > heap[parent(index)].relevancepoints) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
        else
            break;
    }
}

// Restores the heap property going down from a given index
// Time Complexity: O(log n) in the worst case, where n is the number of nodes
// Space Complexity: O(1)
void MaxHeap::heapifydown(size_t index) {
    while (left_child(index) < heap.getcurrent() &&
           (heap[index].relevancepoints < heap[left_child(index)].relevancepoints) ||
           (right_child(index) < heap.getcurrent() &&
            heap[index].relevancepoints < heap[right_child(index)].relevancepoints))
    {
        int max = index;
        if (heap[max].relevancepoints < heap[left_child(index)].relevancepoints)
            max = left_child(index);
        if (right_child(index) < heap.getcurrent() &&
            heap[max].relevancepoints < heap[right_child(index)].relevancepoints)
            max = right_child(index);
        if (max == index)
            break;
        swap(heap[max], heap[index]);
        index = max;
    }
}

// Inserts a new value into the heap
// Time Complexity: O(log n) in the worst case, where n is the number of nodes
// Space Complexity: O(1) auxiliary (excluding the space required to store the heap itself)
void MaxHeap::insert(maxHeapNode value) {
    heap.push(value);
    heapifyup(heap.getcurrent() - 1);
}

// Extracts the maximum value from the heap
// Time Complexity: O(log n) in the worst case, where n is the number of nodes
// Space Complexity: O(1)
maxHeapNode MaxHeap::extract_max() {
    maxHeapNode value = heap[0];
    swap(heap[0], heap[heap.getcurrent()-1]);
    heap.setcurrent(heap.getcurrent()-1);
    heapifydown(0);
    return value;
}

// Checks if the heap is a valid max heap
// Time Complexity: O(n), where n is the number of nodes
// Space Complexity: O(1)
bool MaxHeap::is_a_max_heap() {
    int size = heap.getcurrent();
    for (int i = size/2 - 1; i >= 0; i--) {
        if (right_child(i) < size && heap[right_child(i)].relevancepoints > heap[i].relevancepoints)
            return false;
        if (left_child(i) < size && heap[left_child(i)].relevancepoints > heap[i].relevancepoints)
            return false;
    }
    return true;
}

// Returns the minimum value in the max heap (one of the leaf nodes)
// Time Complexity: O(n), where n is the number of nodes
// Space Complexity: O(1)
maxHeapNode MaxHeap::min_maxheap() {
    int size = heap.getcurrent();
    maxHeapNode min = heap[0];
    for (int i = size/2; i < size; i++) // Only check the leaf nodes
        if (heap[i].relevancepoints < min.relevancepoints)
            min = heap[i];
    return min;
}

// Returns the maximum value (the root) without removing it
// Time Complexity: O(1)
// Space Complexity: O(1)
maxHeapNode MaxHeap::peaktop() {
    return heap[0];
}

// Checks if the heap is empty
// Time Complexity: O(1)
// Space Complexity: O(1)
bool MaxHeap::isEmpty() const {
    return heap.empty();
}

// Builds a max heap from an unsorted array
// Time Complexity: O(n), where n is the number of nodes
// Space Complexity: O(1) auxiliary (excluding the space required to store the heap itself)
void MaxHeap::build_heap() {
    for (int i = heap.getcurrent() / 2; i >= 0; i--) {
        heapifydown(i);
    }
}

// Clears the heap
// Time Complexity: O(n), where n is the number of nodes (assuming customVector's clear method is O(n))
// Space Complexity: O(1) auxiliary (excluding the space required to store the heap itself)
void MaxHeap::clear() {
    heap.clear();
}

// Sorts the heap using heap sort algorithm
// Time Complexity: O(n log n), where n is the number of nodes
// Space Complexity: O(1) auxiliary (excluding the space required to store the heap itself)
void MaxHeap::heap_sort() {
    build_heap();
    int count = heap.getcurrent() - 1;
    while (count > 0) {
        swap(heap[0], heap[count]);
        heap.setcurrent(count);
        heapifydown(0);
        count--;
    }
}

