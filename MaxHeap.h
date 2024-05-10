#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // Include this for out_of_range
#include "customVector.h"
#include "Article.h"

using namespace std;

class maxHeapNode{
public:
    Article* article;
    float relevancepoints;

    maxHeapNode() :article(nullptr), relevancepoints(0){}

    maxHeapNode(Article* a, float f) :article(a), relevancepoints(f){}


};


class MaxHeap {
private:
    customVector<maxHeapNode> heap;
public:
    MaxHeap();
    MaxHeap(customVector<maxHeapNode>);

    int parent(int);
    int left_child(int x);
    int right_child(int x);
    void swap(maxHeapNode &x, maxHeapNode &y);

    void heapifyup(size_t index);
    void heapifydown(size_t index);
    void insert(maxHeapNode value);
    maxHeapNode extract_max();                       //to remove later i we don't use it
    bool is_a_max_heap();                 //to remove later i we don't use it
    maxHeapNode min_maxheap();
    maxHeapNode peaktop();
    bool isEmpty() const;
    void build_heap();

    void heap_sort();
};




#endif // MAX_HEAP_H
