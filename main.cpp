#include <iostream>
#include "Article.h"
#include "BinarySearchTree.h"
#include "MaxHeap.h"

void printArticle(const Article& article) {
    std::cout << "Title: " << article.title
              << ", Source: " << article.source
              << ", Date: " << article.publicationDate
              << ", Relevance: " << article.relevanceScore << std::endl;
}

int main() {
    // Create some articles
    Article a1("News One", "Source A", "2024-04-30", 0.8);
    Article a2("News Two", "Source B", "2024-04-29", 0.6);
    Article a3("News Three", "Source C", "2024-04-28", 0.9);

    // Insert into a binary search tree
    BinarySearchTree<Article> bst;
    bst.insert(a1);
    bst.insert(a2);
    bst.insert(a3);

    std::cout << "Articles in BST (sorted by date):" << std::endl;
    bst.inOrderTraversal(printArticle);

    // Insert into a max-heap for relevance
    MaxHeap<Article> heap;
    heap.insert(a1);
    heap.insert(a2);
    heap.insert(a3);

    std::cout << "\nArticles in Max-Heap (prioritized by relevance):" << std::endl;
    while (!heap.isEmpty()) {
        Article max = heap.extractMax();
        printArticle(max);
    }

    return 0;
}
