//
// Created by tarek on 5/18/2024.
//

#ifndef CUSTOMIZED_NEWS_FEED_ALGORITHM_FUNCTIONALITIES_H
#define CUSTOMIZED_NEWS_FEED_ALGORITHM_FUNCTIONALITIES_H

#include <iostream>
#include "Accounts.h"
#include "Article.h"
#include <limits>


using namespace std;

void loadFiles();

void saveFiles();

string login(string, string);

void implementAdminChoice(Admins&, int);

// Function to display the admin menu and handle admin functionalities
void adminMenu();

// Function to display the user menu and handle user functionalities
void userMenu();


void displayNewsFeed(Users& user);


void displayArticle(const Article& article);



void userInteraction(Users& user);

#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_FUNCTIONALITIES_H
