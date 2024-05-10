//
// Created by tarek on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H

#include <string>
#include "Date.h"
#include "customVector.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>

using namespace std;



class Article {
private:
    string title;
    string content;
    string category;
    string source;
    string author;
    Date publicationDate;

    static customVector<Article> articles;

public:
    Article();
    Article(const string& title, const string& content, const string& category, const string& source, const string& author, Date publicationDate);


    string getTitle() const;
    string getContent() const;
    string getCategory() const;
    string getSource() const;
    string getAuthor() const;
    Date getPublicationDate() const;
    static customVector<Article>& getArticles();

    void setTitle(const string& title);
    void setContent(const string& content);
    void setCategory(const string& category);
    void setSource(const string& source);
    void setAuthor(const string& author);
    void setPublicationDate(const Date& publicationDate);



    Article search(Article);
    //vector<Article> filterBySource(const vector<Article>& articles, const string& source);   //to be removed

    bool operator ==(Article);
    bool operator !=(Article);

    static bool saveArticles();
    static bool loadArticles();

};





#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
