//
// Created by tarek on 5/9/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H

#include <string>
#include <iostream>
#include "Article.h"
#include "MaxHeap.h"
#include <math.h>

using namespace std;


class Accounts {
protected:
    string username;
    string password;

public:
    Accounts();
    Accounts(string, string);
    void setusername(string);
    void setpassword(string);

    string getusername();
    string getpassword();



};

class Admins : public Accounts{
private:
    static customVector<Admins> admins;
public:
    Admins();
    Admins(string, string);

    static customVector<Admins>& getAdmins();

    void addArticle(Article);

    static bool saveAdmins();
    static bool loadAdmin();

};


struct prefrenceNode{
    string category;
    unsigned int count;
};

class Users : public Accounts{
private:
    string prefrence;
    static customVector<Users> users;

public:

    customVector<prefrenceNode> prefrenceVector;

    MaxHeap heapOfPrefrences;

    Users();
    Users(string, string, string);

    void setPrefrence(string);

    string getPrefrence();
    static customVector<Users>& getUsers();

    float calcScore(Article);
    Users findByUsername(string);
    void loadPrefrenceVector();
    void savePrefrenceVector();

    customVector<Article> filterBySource(const string& source);
    customVector<Article> filterByAuthor(const string& Author);
    customVector<Article> filterByCategory(const string& cat);

    void buildHeap(); //to be looked at

    void likeArticle(string);
    void notInterested(maxHeapNode& node);  //lw fe wa2t
    // to add mark as read


    static bool saveUsers();
    static bool loadUsers();

};



#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_ACCOUNTS_H
