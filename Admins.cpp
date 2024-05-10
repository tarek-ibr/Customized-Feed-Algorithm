//
// Created by tarek on 5/9/2024.
//
#include "Accounts.h"

Admins::Admins(string u, string p) : Accounts(u, p){}

void Admins::addArticle(Article a) {
    singleLinkedList& articles = Article::getArticles();
    articles.addToTail(a);
}

