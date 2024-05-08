//
// Created by AhmedElbehiry on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_BINARYSEARCHTREE_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_BINARYSEARCHTREE_H

#include <iostream>
#include <memory>

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const T& d) : data(d) {}
    };

    std::unique_ptr<Node> root;

    void insert(std::unique_ptr<Node>& node, const T& value) {
        if (!node) {
            node = std::make_unique<Node>(value); // Create a new node with the given value
        } else if (value < node->data) {
            insert(node->left, value); // Recursive insert on the left
        } else {
            insert(node->right, value); // Recursive insert on the right
        }
    }


    void inOrder(Node* node, void (*process)(const T&)) {
        if (!node) return;
        inOrder(node->left.get(), process);
        process(node->data);
        inOrder(node->right.get(), process);
    }

public:
    void insert(const T& value) {
        insert(root, value); // Root-level insert with the given value
    }

    void inOrderTraversal(void (*process)(const T&)) {
        inOrder(root.get(), process);
    }
};


#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_BINARYSEARCHTREE_H
