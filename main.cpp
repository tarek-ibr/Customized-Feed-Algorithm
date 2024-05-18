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

    Users u2= u1[0];

    cout<<a1[0].getusername()<<endl;

    cout<<u1[0].getusername()<<endl;

    cout<<s1[0].getTitle()<<endl;


    //displayNewsFeed(u1[0]);

    u2.loadPrefrenceVector();
    cout<<u2.prefrenceVector[0].category;
    u2.prefrenceVector[0].category = "cars";
    u2.savePrefrenceVector();
    u2.getPrefrence();


    Article::saveArticles();
    Admins::saveAdmins();
    Users::saveUsers();

    system("pause");

    return 0;
}

