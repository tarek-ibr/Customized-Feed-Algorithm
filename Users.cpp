//
// Created by tarek on 5/9/2024.
//

#include "Accounts.h"
#include "Article.h"

singleLinkedList<Users> Users::users = singleLinkedList<Users>();

Users::Users(string u, string pass, string pref) : Accounts(u, pass), prefrence(pref){}


void Users::setPrefrence(string p) {
    prefrence = p;
}

string Users::getPrefrence() {
    return prefrence;
}

singleLinkedList<Users> &Users::getUsers() {
    return users;
}

bool Users::saveUsers() {
    ofstream file("users.json");

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json output;


    // Add new articles to the existing JSON array
    for (sllnode<Users>* temp=users.getHead(); temp!=nullptr; temp=temp->next) {
        nlohmann::json jsonObj;
        jsonObj["username"] = temp->info.username;
        jsonObj["password"] = temp->info.password;
        jsonObj["prefrence"] = temp->info.prefrence;

        output.push_back(jsonObj);  // Append the new article to the JSON array
    }

    file << setw(4) << output;
    file.close();

    return true;
}

bool Users::loadUsers() {
    users.clear();

    ifstream file("users.json");

    if (!file.is_open()) {//making sure books.json was opened successfully
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json jsonArray;
    file >> jsonArray;

    for (const auto& jsonObj : jsonArray) {
        string username = jsonObj["username"];
        string password = jsonObj["password"];
        string prefrence = jsonObj["prefrence"];

        users.addToTail(Users(username, password, prefrence));
    }
    file.close();

    return true;
}


