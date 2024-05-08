#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <vector>
#include <algorithm>
#include <stdexcept> // Include this for std::out_of_range

template<typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    void heapifyDown(size_t index) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(size_t index) {
        if (index == 0) return;
        size_t parent = (index - 1) / 2;

        if (heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        T max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

#endif // MAX_HEAP_H
