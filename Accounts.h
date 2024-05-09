//
// Created by tarek on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H

#include <string>
#include <iostream>

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
public:
    Admins(string, string);
    void addArticle();

};

class Users : public Accounts{
private:
    string prefrence;
public:
    Users(string, string, string);
    void setPrefrence(string);

    string getPrefrence();


};


#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H
