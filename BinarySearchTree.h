//
// Created by AhmedElbehiry on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_BINARYSEARCHTREE_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_BINARYSEARCHTREE_H

#include <iostream>
#include <memory>

using namespace std;

template<typename T>                        //all the file is to be removed if we don't use it
class Node {
    T data;
    Node* left;
    Node* right;
public:
    Node(const T& d);
    Node(const T& d, Node*, Node*);

};

template<typename T>
class BinarySearchTree {
private:
    unique_ptr<Node<T>> root;

    void insert(unique_ptr<Node<T>>& node, const T& value);


    void inOrder(Node<T>* node, void (*process)(const T&));
public:

    void insert(const T& value);

    void inOrderTraversal(void (*process)(const T&));
};


#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_BINARYSEARCHTREE_H
