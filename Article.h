//
// Created by tarek on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H

#include <string>
#include "Date.h"
#include "customVector.h"
#include "json.h"
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
    string type;

    static customVector<Article> articles;

public:
    Article();
    Article( string ,  string ,  string ,  string ,  string , Date,string );


    string getTitle() const;
    string getContent() const;
    string getCategory() const;
    string getSource() const;
    string getAuthor() const;
    Date getPublicationDate() const;
    string getType() const;
    static customVector<Article>& getArticles();

    void setTitle(const string& title);
    void setContent(const string& content);
    void setCategory(const string& category);
    void setSource(const string& source);
    void setAuthor(const string& author);
    void setType(const string& type);
    void setPublicationDate(const Date& publicationDate);


    void displayArticle();
    Article search(Article);

    bool operator ==(Article);
    bool operator !=(Article);

    static bool saveArticles();
    static bool loadArticles();

};





#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_ARTICLE_H
