//
// Created by tarek on 5/10/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_CUSTOMSINGLELINKEDLIST_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_CUSTOMSINGLELINKEDLIST_H

#include "iostream"

using namespace std;

template<typename T>
class sllnode{
public:
    T info;
    sllnode* next;

    sllnode();
    sllnode(T);
    sllnode(T, sllnode*);
};

template<typename T>
class singleLinkedList {
    sllnode<T>* head, * tail;
public:
    singleLinkedList();

    sllnode<T>* getHead();
    sllnode<T>* getTail();

    bool isEmpty();
    void addToHead(T el);
    void addToTail(T el);
    T deleteFromHead();
    T deleteFromTail();
    void deletenode(T el);
    bool isInList(T el) const;
    void clear();

    ~singleLinkedList();
};



template<typename T>
sllnode<T>::sllnode(){
    next =0;
}

template<typename T>
sllnode<T>::sllnode(T i){
    info=i;
    next=0;
}

template<typename T>
sllnode<T>::sllnode(T i, sllnode* n){
    info=i;
    next=n;
}

template<typename T>
singleLinkedList<T>::singleLinkedList(){
    head=tail=0;
}

template<typename T>
sllnode<T> *singleLinkedList<T>::getHead() {
    return head;
}

template<typename T>
sllnode<T> *singleLinkedList<T>::getTail() {
    return tail;
}

template<typename T>
bool singleLinkedList<T>::isEmpty(){
    return head==0;
}

template<typename T>
void singleLinkedList<T>::addToHead(T el){
    head=new sllnode<T>(el, head);
    if (tail==0)
        tail=head;
}

template<typename T>
void singleLinkedList<T>::addToTail(T el){
    if (isEmpty())
        head=tail=new sllnode<T>(el);
    else {
        tail->next=new sllnode<T>(el);
        tail=tail->next;
    }
}

template<typename T>
T singleLinkedList<T>::deleteFromHead() {
    if(!isEmpty()){
        T el=head->info;
        if (head == tail){
            delete head;
            head=tail=0;
        }
        else{
            sllnode<T>* temp=head;
            head=head->next;
            delete temp;
        }
        return el;
    }
    else
        cout<< "the list is empty";
    return NULL;
}

template<typename T>
T singleLinkedList<T>::deleteFromTail(){
    if(!isEmpty()){
        T el=tail->info;
        if (head == tail){
            delete tail;
            head=tail=0;
        }
        else{
            sllnode<T>* temp;
            for(temp=head;temp->next!=tail;temp=temp->next);
            tail=temp;
            temp=temp->next;
            delete temp;
            tail->next=0;
        }
        return el;
    }
    else
        cout<< "the list is empty";
    return NULL;
}

template<typename T>
void singleLinkedList<T>::deletenode(T el){
    if(!isEmpty()){
        if (head->info == el){
            deleteFromHead();
        }
        else if(tail->info == el){
            deleteFromHead();
        }
        else{
            sllnode<T>* temp,*temp2;
            for(temp=head;temp->next->info!=el&&temp->next!=tail;temp=temp->next);
            temp2=temp->next;
            if (temp2!=tail) {
                temp->next = temp->next->next;
                delete temp2;
            }
        }
    }
    else
        cout<< "the list is empty";
}

template<typename T>
bool singleLinkedList<T>::isInList(T el) const{
    sllnode<T>* temp;
    for(temp=head;temp->info!=el&&temp!=tail;temp=temp->next);
    return temp->info==el;
}

template<typename T>
void singleLinkedList<T>::clear() {
    sllnode<T>* p=head;
    while (head!=0){
        p=p->next;
        delete head;
        head=p;
    }
    head=tail=0;
}

template<typename T>
singleLinkedList<T>::~singleLinkedList(){
    sllnode<T>* p=head;
    while (head!=0){
        p=p->next;
        delete head;
        head=p;
    }
    head=tail=0;
}

#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_CUSTOMSINGLELINKEDLIST_H
