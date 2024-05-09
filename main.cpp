#include <iostream>
#include "Accounts.h"
#include "Article.h"
#include "Date.h"
#include "MaxHeap.h"
#include "singleLinkedList.h"



int main() {

    Article::loadArticles();

    singleLinkedList<Article> s1 = Article::getArticles();

    sllnode<Article>* s2 = s1.getHead();
    cout<<s2->info.getTitle();

    Article::saveArticles();

    system("pause");

    return 0;
}
