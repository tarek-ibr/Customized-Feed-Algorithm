//
// Created by tarek on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H

#include <string>
#include <vector>
#include "Date.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include "singleLinkedList.h"

using namespace std;

class Article {
private:
    string title;
    string content;
    string category;
    string source;
    string author;
    Date publicationDate;

    static singleLinkedList<Article> articles;

public:

    Article(const string& title, const string& content, const string& category, const string& source, const string& author, Date publicationDate);


    string getTitle() const;
    string getContent() const;
    string getCategory() const;
    string getSource() const;
    string getAuthor() const;
    Date getPublicationDate() const;
    static singleLinkedList<Article>& getArticles();

    void setTitle(const string& title);
    void setContent(const string& content);
    void setCategory(const string& category);
    void setSource(const string& source);
    void setAuthor(const string& author);
    void setPublicationDate(const Date& publicationDate);
    
    

    Article searchByTitle(const vector<Article>& articles, const string& title);
    vector<Article> filterBySource(const vector<Article>& articles, const string& source);

    static bool saveArticles();
    static bool loadArticles();

};



#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
