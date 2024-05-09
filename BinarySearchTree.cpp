//
// Created by tarek on 5/9/2024.
//

#include "BinarySearchTree.h"

template<typename T>
Node<T>::Node(const T& d) : data(d), right(NULL), left(NULL) {}

template<typename T>
Node<T>::Node(const T& d, Node* r, Node* l) : data(d), right(r), left(l) {}

template<typename T>
void BinarySearchTree<T>::insert(unique_ptr<Node<T>>& node, const T& value) {
    if (!node) {
        node = std::make_unique<Node<T>>(value); // Create a new node with the given value
    } else if (value < node->data) {
        insert(node->left, value); // Recursive insert on the left
    } else {
        insert(node->right, value); // Recursive insert on the right
    }
}

template<typename T>
void BinarySearchTree<T>::inOrder(Node<T>* node, void (*process)(const T&)) {
    if (!node) return;
    inOrder(node->left.get(), process);
    process(node->data);
    inOrder(node->right.get(), process);
}

template<typename T>
void BinarySearchTree<T>::insert(const T& value) {
    insert(root, value); // Root-level insert with the given value
}

template<typename T>
void BinarySearchTree<T>::inOrderTraversal(void (*process)(const T&)) {
    inOrder(root.get(), process);
}
