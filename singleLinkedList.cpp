//
// Created by tarek on 5/9/2024.
//

#include "singleLinkedList.h"

template<typename T>
sllnode<T>::sllnode(){
    next =0;
}

template<typename T>
sllnode<T>::sllnode(int i){
    info=i;
    next=0;
}

template<typename T>
sllnode<T>::sllnode(int i, sllnode* n){
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
int singleLinkedList<T>::isEmpty(){
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
int singleLinkedList<T>::deleteFromHead() {
    if(!isEmpty()){
        int el=head->info;
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
    return -1;
}

template<typename T>
int singleLinkedList<T>::deleteFromTail(){
    if(!isEmpty()){
        int el=tail->info;
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
    return -1;
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
void singleLinkedList<T>::printsll(){
    sllnode<T>* temp=head;
    while(temp!=0){
        cout << temp->info<< " ";
        temp=temp->next;
    }
    cout <<"\n";
}

template<typename T>
void singleLinkedList<T>::reverse() {
    if (!(head == tail)&&head!=0) {
        sllnode<T> *temp = tail;
        temp->next = new sllnode<T>(deleteFromHead(),temp->next);
        tail = temp->next;
        while (temp != head) {
            temp->next = new sllnode<T>(deleteFromHead(),temp->next);
        }
    }
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