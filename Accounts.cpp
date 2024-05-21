//
// Created by tarek on 5/9/2024.
//

#include "Accounts.h"

Accounts::Accounts() : username(""), password(""){}

Accounts::Accounts(string u, string p) : username(u), password(p){}

void Accounts::setusername(string u) {
    username = u;
}

void Accounts::setpassword(string p) {
    password = p;
}

string Accounts::getusername() {
    return username;
}

string Accounts::getpassword() {
    return password;
}

void Accounts::addArticle(Article a) {
    customVector<Article>& articles = Article::getArticles();
    articles.push(a);
}

int Accounts::addVideo(string title, string category, string source, string author){
    customVector<Article>& articles = Article::getArticles();
    int num=1;
    for(auto& it: articles){
        if (it.getType()=="video")
            num++;
    }
    articles.push(Article(title, to_string(num), category, source, author, Date::getCrrentDate(), "video"));
    return num;
}