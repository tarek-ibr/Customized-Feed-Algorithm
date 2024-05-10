//
// Created by tarek on 5/9/2024.
//
#include "Accounts.h"
#include "Article.h"


singleLinkedList<Admins> Admins::admins = singleLinkedList<Admins>();

Admins::Admins(string u, string p) : Accounts(u, p){}

singleLinkedList<Admins> &Admins::getAdmins() {
    return admins;
}


void Admins::addArticle(Article a) {
    singleLinkedList<Article>& articles = Article::getArticles();
    articles.addToTail(a);
}

bool Admins::saveAdmins() {
    ofstream file("admins.json");

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json output;


    // Add new articles to the existing JSON array
    for (sllnode<Admins>* temp=admins.getHead(); temp!=nullptr; temp=temp->next) {
        nlohmann::json jsonObj;
        jsonObj["username"] = temp->info.username;
        jsonObj["password"] = temp->info.password;

        output.push_back(jsonObj);  // Append the new article to the JSON array
    }

    file << setw(4) << output;
    file.close();

    return true;
}

bool Admins::loadAdmin() {
    admins.clear();

    ifstream file("admins.json");

    if (!file.is_open()) {//making sure books.json was opened successfully
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json jsonArray;
    file >> jsonArray;

    for (const auto& jsonObj : jsonArray) {
        string username = jsonObj["username"];
        string password = jsonObj["password"];

        admins.addToTail(Admins(username, password));
    }
    file.close();

    return true;
}

