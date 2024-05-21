//
// Created by tarek on 5/9/2024.
//
#include "Accounts.h"
#include "Article.h"


customVector<Admins> Admins::admins = customVector<Admins>();

Admins::Admins() : Accounts(){}

Admins::Admins(string u, string p) : Accounts(u, p){}

customVector<Admins> &Admins::getAdmins() {
    return admins;
}

Admins Admins::findByUsername(string username){
    // Loop through all members
    for(auto it:admins)
    {
        // If the member is found
        if(it.getusername()==username)
        {
            return it;
        }
    }

    return Admins();
}



bool Admins::registerNewUser(string u, string p){
    customVector<Users>& users= Users::getUsers();
    for(auto& it: users){
        if(u==it.getusername()){
            return false;
        }
    }
    Users::getUsers().push(Users(u,p, "", ""));
    return true;
}
bool Admins::removeUser(string u){
    customVector<Users>& users= Users::getUsers();
    bool flag = false;
    size_t index=0;
    for(auto& it: users){
        if(u==it.getusername()){
            users.erase(index);
            flag = true;
        }
        index++;
    }
    return flag;
}

bool Admins::saveAdmins() {
    ofstream file("admins.json");

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json output;


    // Add new articles to the existing JSON array
    for (size_t i=0;i<admins.size();i++) {
        nlohmann::json jsonObj;
        jsonObj["username"] = admins[i].username;
        jsonObj["password"] = admins[i].password;

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

        admins.push(Admins(username, password));
    }
    file.close();

    return true;
}

