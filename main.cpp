#include <iostream>
#include "Article.h"


int main() {

    Article::loadArticles();

    singleLinkedList s1 = Article::getArticles();

    sllnode* s2 = s1.getHead();
    cout<<s2->info.getTitle()<<endl;
    //s2->info.setAuthor("eljooker");

    cout <<Article::saveArticles()<<endl;

    system("pause");

    return 0;
}
