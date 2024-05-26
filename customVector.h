// Created by AhmedElbehiry on 5/10/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_CUSTOMVECTOR_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_CUSTOMVECTOR_H

#include <iostream>

template <typename T>
class customVector {
private:
    T* arr;
    size_t capacity;
    size_t current;
public:
    customVector();
    customVector(const customVector& v);
    customVector& operator=(const customVector& v);
    ~customVector();

    size_t& getcapacity();
    size_t& getcurrent();

    void setcurrent(size_t);

    void push(T data);
    void insert(size_t index, T data);
    void erase(size_t index);
    void clear();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
    bool empty() const;
    void print() const;
    T* begin();
    T* end();
};

// Constructor
// Initializes an empty customVector with a capacity of 1
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
customVector<T>::customVector() : arr(new T[1]), capacity(1), current(0) {}

// Copy Constructor
// Creates a copy of another customVector
// Time Complexity: O(n), where n is the number of elements in the vector
// Space Complexity: O(n)
template <typename T>
customVector<T>::customVector(const customVector& v)
        : arr(new T[v.capacity]), capacity(v.capacity), current(v.current) {
    for (size_t i = 0; i < current; ++i) {
        arr[i] = v.arr[i];
    }
}

// Copy Assignment Operator
// Assigns the contents of another customVector to this one
// Time Complexity: O(n), where n is the number of elements in the vector
// Space Complexity: O(n)
template <typename T>
customVector<T>& customVector<T>::operator=(const customVector& v) {
    if (this != &v) {
        delete[] arr; // free old memory
        arr = new T[v.capacity];
        capacity = v.capacity;
        current = v.current;
        for (size_t i = 0; i < current; ++i) {
            arr[i] = v.arr[i];
        }
    }
    return *this;
}

// Destructor
// Cleans up the allocated memory
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
customVector<T>::~customVector() {
    delete[] arr;
}

// Returns the capacity of the vector
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
size_t& customVector<T>::getcapacity(){
    return capacity;
}

// Returns the current size of the vector
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
size_t& customVector<T>::getcurrent(){
    return current;
}

// Sets the current size of the vector
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
void customVector<T>::setcurrent(size_t c){
    current = c;
}

// Push method
// Adds a new element to the end of the vector, resizing if necessary
// Time Complexity: O(1) amortized, O(n) worst-case when resizing
// Space Complexity: O(n)
template <typename T>
void customVector<T>::push(T data) {
    if (current == capacity) {
        capacity *= 2;
        T* temp = new T[capacity];
        for (size_t i = 0; i < current; ++i) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    arr[current++] = data;
}

// Insert method
// Inserts a new element at the specified index, resizing if necessary
// Time Complexity: O(n) in the worst case
// Space Complexity: O(n)
template <typename T>
void customVector<T>::insert(size_t index, T data) {
    if (index > current) {
        throw std::out_of_range("Index out of range");
    }
    if (current == capacity) {
        capacity *= 2;
        T* temp = new T[capacity];
        for (size_t i = 0; i < current; ++i) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    for (size_t i = current; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = data;
    ++current;
}

// Erase method
// Removes the element at the specified index
// Time Complexity: O(n) in the worst case
// Space Complexity: O(1)
template <typename T>
void customVector<T>::erase(size_t index) {
    if (index >= current) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < current - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --current;
}

// Clear method
// Clears the vector
// Time Complexity: O(n), where n is the number of elements in the vector
// Space Complexity: O(1) auxiliary (excluding the space required to store the vector itself)
template<typename T>
void customVector<T>::clear() {
    current = 0;
    delete[] arr;
    arr = new T[1];
    capacity = 1;
}

// Operator[]
// Returns the element at the specified index
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
T& customVector<T>::operator[](size_t index) {
    return arr[index];
}

// Operator[] const
// Returns the element at the specified index (const version)
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
const T& customVector<T>::operator[](size_t index) const {
    return arr[index];
}

// Size method
// Returns the number of elements in the vector
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
size_t customVector<T>::size() const {
    return current;
}

// Empty method
// Checks if the vector is empty
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
bool customVector<T>::empty() const {
    return current == 0;
}

// Print method
// Prints the elements of the vector
// Time Complexity: O(n), where n is the number of elements in the vector
// Space Complexity: O(1)
template <typename T>
void customVector<T>::print() const {
    for (size_t i = 0; i < current; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

// Begin method
// Returns a pointer to the first element
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
T* customVector<T>::begin() {
    return arr;
}

// End method
// Returns a pointer to one past the last element
// Time Complexity: O(1)
// Space Complexity: O(1)
template <typename T>
T* customVector<T>::end() {
    return arr + current;
}

#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_CUSTOMVECTOR_H