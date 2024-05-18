//
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
template <typename T>
customVector<T>::customVector() : arr(new T[1]), capacity(1), current(0) {}

// Copy Constructor
template <typename T>
customVector<T>::customVector(const customVector& v)
        : arr(new T[v.capacity]), capacity(v.capacity), current(v.current) {
    for (size_t i = 0; i < current; ++i) {
        arr[i] = v.arr[i];
    }
}


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
template <typename T>
customVector<T>::~customVector() {
    delete[] arr;
}

template <typename T>
size_t& customVector<T>::getcapacity(){
    return capacity;
}

template <typename T>
size_t& customVector<T>::getcurrent(){
    return current;
}

template <typename T>
void customVector<T>::setcurrent(size_t c){
    current = c;
}

// Push method
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

template<typename T>
void customVector<T>::clear() {
    current = 0;
    delete[] arr;
    arr = new T[1];
    capacity = 1;
}


// Operator[]
template <typename T>
T& customVector<T>::operator[](size_t index) {
    if (index >= current) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
const T& customVector<T>::operator[](size_t index) const {
    if (index >= current) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

// Size method
template <typename T>
size_t customVector<T>::size() const {
    return current;
}

// Empty method
template <typename T>
bool customVector<T>::empty() const {
    return current == 0;
}

// Print method
template <typename T>
void customVector<T>::print() const {
    for (size_t i = 0; i < current; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}


template <typename T>
T* customVector<T>::begin() {
    return arr;
}

template <typename T>
T* customVector<T>::end() {
    return arr +current;
}





#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_CUSTOMVECTOR_H

