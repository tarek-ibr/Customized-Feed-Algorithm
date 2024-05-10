#include <iostream>
#include "Article.h"
#include "Accounts.h"


int main() {

    Article::loadArticles();

    singleLinkedList& s1 = Article::getArticles();
    Admins a1 = Admins("tarek", "1234");
    //a1.addArticle(Article());

    sllnode* s2 = s1.getHead();
    cout<<s2->info.getTitle()<<endl;

    //sllnode* s3 = s1.getTail();
    //cout<<s3->info.getTitle()<<endl;

    //s2->info.setAuthor("eljooker");

    cout <<Article::saveArticles()<<endl;

    system("pause");

    return 0;
}
