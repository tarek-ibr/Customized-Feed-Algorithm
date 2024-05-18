#include <iostream>
#include "Article.h"
#include "Accounts.h"
#include "functionalities.h"


int main() {

    Article::loadArticles();
    Admins::loadAdmin();
    Users::loadUsers();


    customVector<Article>& s1 = Article::getArticles();
    customVector<Admins>& a1 = Admins::getAdmins();
    customVector<Users>& u1 = Users::getUsers();


    cout<<a1[0].getusername()<<endl;

    cout<<u1[0].getusername()<<endl;

    cout<<s1[0].getTitle()<<endl;


    displayNewsFeed(u1[0]);


    Article::saveArticles();
    Admins::saveAdmins();
    Users::saveUsers();

    system("pause");

    return 0;
}

