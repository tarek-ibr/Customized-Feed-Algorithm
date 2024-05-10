//
// Created by tarek on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H

#include <string>
#include <iostream>
#include "Article.h"

using namespace std;

class Accounts {
protected:
    string username;
    string password;
public:
    Accounts(string, string);
    void setusername(string);
    void setpassword(string);

    string getusername();
    string getpassword();



};

class Admins : public Accounts{
private:
    static singleLinkedList<Admins> admins;
public:
    Admins(string, string);

    static singleLinkedList<Admins>& getAdmins();

    void addArticle(Article);

    static bool saveAdmins();
    static bool loadAdmin();

};

class Users : public Accounts{
private:
    string prefrence;
    static singleLinkedList<Users> users;
public:
    Users(string, string, string);
    void setPrefrence(string);

    string getPrefrence();
    static singleLinkedList<Users>& getUsers();



    static bool saveUsers();
    static bool loadUsers();

};



#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H
