#include <iostream>
#include "Article.h"
#include "BinarySearchTree.h"
#include "MaxHeap.h"
#include "ArticleUtils.h"  // Include ArticleUtils.h for JSON, search, and filter functions

void printArticle(const Article& article) {
    std::cout << "Title: " << article.title
              << ", Source: " << article.source
              << ", Date: " << article.publicationDate
              << ", Relevance: " << article.relevanceScore << std::endl;
}

int main() {
    std::vector<Article> articles;

    // Load articles from a JSON file
    std::string filename = "articles.json";
    articles = loadFromJSON(filename);

    // Demonstrate search functionality
    std::cout << "\nSearching for 'News One':" << std::endl;
    try {
        Article found = searchByTitle(articles, "News One");
        printArticle(found);
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Demonstrate filter functionality
    std::cout << "\nFiltering by source 'Source B':" << std::endl;
    auto filtered = filterBySource(articles, "Source B");
    for (const auto& article : filtered) {
        printArticle(article);
    }

    // Insert into a binary search tree (sorted by date)
    BinarySearchTree<Article> bst;
    for (const auto& article : articles) {
        bst.insert(article);
    }

    std::cout << "\nArticles in BST (sorted by date):" << std::endl;
    bst.inOrderTraversal(printArticle);

    // Insert into a max-heap (prioritized by relevance)
    MaxHeap<Article> heap;
    for (const auto& article : articles) {
        heap.insert(article);
    }

    std::cout << "\nArticles in Max-Heap (prioritized by relevance):" << std::endl;
    while (!heap.isEmpty()) {
        Article max = heap.extractMax();
        printArticle(max);
    }

    std::vector<Article> articlesTest = {
            Article("Test Article 1", "Source X", "2024-05-01", 0.7),
            Article("Test Article 2", "Source Y", "2024-05-02", 0.9),
            Article("Test Article 3", "Source Z", "2024-05-03", 0.6)
    };

    // Save to JSON
    std::string filenameTest = "test_articles.json";
    saveToJSON(articlesTest, filename);

    return 0;
}
