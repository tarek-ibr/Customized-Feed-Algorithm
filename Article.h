//
// Created by AhmedElbehiry on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H

#include <string>

class Article {
public:
    std::string title;
    std::string source;
    std::string publicationDate;
    double relevanceScore;

    Article(const std::string& t, const std::string& s, const std::string& pd, double rs)
            : title(t), source(s), publicationDate(pd), relevanceScore(rs) {}

    bool operator<(const Article& other) const {
        return publicationDate < other.publicationDate;
    }

    bool operator>(const Article& other) const {
        return relevanceScore > other.relevanceScore;
    }
};

#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
