#ifndef ARTICLE_UTILS_H
#define ARTICLE_UTILS_H

#include <nlohmann/json.hpp>
#include "Article.h"
#include <fstream>
#include <vector>
#include <stdexcept>  // For std::runtime_error

void saveToJSON(const std::vector<Article>& articles, const std::string& filename) {
    nlohmann::json jsonArray = nlohmann::json::array();

    for (const auto& article : articles) {
        nlohmann::json jsonObj;
        jsonObj["title"] = article.title;
        jsonObj["source"] = article.source;
        jsonObj["publicationDate"] = article.publicationDate;
        jsonObj["relevanceScore"] = article.relevanceScore;
        jsonArray.push_back(jsonObj);
    }

    std::ofstream file(filename);
    file << jsonArray.dump(4);  // Pretty print with 4 spaces
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
