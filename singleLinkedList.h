//
// Created by tarek on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_SINGLELINKEDLIST_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_SINGLELINKEDLIST_H

#include <iostream>

using namespace std;

template<typename T>
class sllnode{
public:
    T info;
    sllnode* next;

    sllnode();
    sllnode(int);
    sllnode(int, sllnode*);
};

template<typename T>
class singleLinkedList {
    sllnode<T>* head, * tail;
public:
    singleLinkedList();

    sllnode<T>* getHead();
    sllnode<T>* getTail();

    int isEmpty();
    void addToHead(T el);
    void addToTail(T el);
    int deleteFromHead();
    int deleteFromTail();
    void deletenode(T el);
    bool isInList(T el) const;
    void printsll();
    void reverse();
    void clear();

    ~singleLinkedList();
};



#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_SINGLELINKEDLIST_H
