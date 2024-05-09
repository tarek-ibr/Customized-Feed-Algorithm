#ifndef ARTICLE_UTILS_H
#define ARTICLE_UTILS_H

#include <nlohmann/json.hpp>
#include "Article.h"
#include <fstream>
#include <vector>
#include <stdexcept>  // For std::runtime_error

void saveToJSON(const std::vector<Article>& newArticles, const std::string& filename) {
    nlohmann::json jsonArray;

    // Check if the file exists
    std::ifstream infile(filename);
    if (infile.good()) {  // If the file exists, read its content
        infile >> jsonArray;  // Load existing data
    } else {
        jsonArray = nlohmann::json::array();  // Initialize an empty array if the file doesn't exist
    }

    // Add new articles to the existing JSON array
    for (const auto& article : newArticles) {
        nlohmann::json jsonObj;
        jsonObj["title"] = article.title;
        jsonObj["source"] = article.source;
        jsonObj["publicationDate"] = article.publicationDate;
        jsonObj["relevanceScore"] = article.relevanceScore;
        jsonArray.push_back(jsonObj);  // Append the new article to the JSON array
    }

    // Save the updated data to the JSON file
    std::ofstream outfile(filename);  // Open the file for writing
    outfile << jsonArray.dump(4);  // Write the updated JSON data, pretty-printed with 4 spaces
}

std::vector<Article> loadFromJSON(const std::string& filename) {
    std::vector<Article> articles;

    std::ifstream file(filename);
    nlohmann::json jsonArray;
    file >> jsonArray;

    for (const auto& jsonObj : jsonArray) {
        std::string title = jsonObj["title"];
        std::string source = jsonObj["source"];
        std::string publicationDate = jsonObj["publicationDate"];
        double relevanceScore = jsonObj["relevanceScore"];

        articles.emplace_back(title, source, publicationDate, relevanceScore);
    }

    return articles;
}

Article searchByTitle(const std::vector<Article>& articles, const std::string& title) {
    for (const auto& article : articles) {
        if (article.title == title) {
            return article;
        }
    }
    throw std::runtime_error("Article not found");
}

std::vector<Article> filterBySource(const std::vector<Article>& articles, const std::string& source) {
    std::vector<Article> filtered;
    for (const auto& article : articles) {
        if (article.source == source) {
            filtered.push_back(article);
        }
    }
    return filtered;
}

#endif  // ARTICLE_UTILS_H
