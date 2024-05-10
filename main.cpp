#include <iostream>
#include "Article.h"
#include "Accounts.h"


int main() {

    Article::loadArticles();
    Admins::loadAdmin();
    Users::loadUsers();


    singleLinkedList<Article>& s1 = Article::getArticles();
    singleLinkedList<Admins>& a1 = Admins::getAdmins();
    singleLinkedList<Users>& u1 = Users::getUsers();


    sllnode<Admins>* a2 = a1.getHead();
    cout<<a2->info.getusername()<<endl;

    sllnode<Users>* u2 = u1.getHead();
    cout<<u2->info.getusername()<<endl;

    sllnode<Article>* s2 = s1.getHead();
    cout<<s2->info.getTitle()<<endl;

    //sllnode* s3 = s1.getTail();
    //cout<<s3->info.getTitle()<<endl;

    //s2->info.setAuthor("eljooker");




    Article::saveArticles();
    Admins::saveAdmins();
    Users::saveUsers();

    system("pause");

    return 0;
}
