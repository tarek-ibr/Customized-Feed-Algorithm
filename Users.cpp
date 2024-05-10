//
// Created by tarek on 5/9/2024.
//

#include "Accounts.h"
#include "Article.h"

customVector<Users> Users::users = customVector<Users>();

Users::Users() : Accounts(){}

Users::Users(string u, string pass, string pref) : Accounts(u, pass), prefrence(pref){}


void Users::setPrefrence(string p) {
    prefrence = p;
}

string Users::getPrefrence() {
    return prefrence;
}

customVector<Users> &Users::getUsers() {
    return users;
}

float Users::calcScore(Article A){
    float score = 0;
    if(A.getCategory() == prefrence)
        score+=0.15;
    if( (Date::getCrrentDate() - A.getPublicationDate()) < 7)
        score+=0.15;
    return score;
}

bool Users::saveUsers() {
    ofstream file("users.json");

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json output;


    // Add new articles to the existing JSON array
    for (size_t i=0;i<users.size();i++) {
        nlohmann::json jsonObj;
        jsonObj["username"] = users[i].username;
        jsonObj["password"] = users[i].password;
        jsonObj["prefrence"] = users[i].prefrence;

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

        users.push(Users(username, password, prefrence));
    }
    file.close();

    return true;
}


