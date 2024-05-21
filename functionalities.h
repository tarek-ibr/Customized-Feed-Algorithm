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
void implementUserChoice(Users&, int, Article&);



#endif //CUSTOMIZED_NEWS_FEED_ALGORITHM_FUNCTIONALITIES_H
