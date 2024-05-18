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
        score+=0.4;
    if( (Date::getCrrentDate() - A.getPublicationDate()) < 7)
        score+=0.15;
    return score;
}

Users Users::findByUsername(string username){
    // Loop through all members
    for(auto it:users)
    {
        // If the member is found
        if(it.getusername()==username)
        {
            return it;
        }
    }
    cout<<"Couldn't Find member"<<endl;

    return Users();
}

void Users::loadPrefrenceVector(){
    bool flag=0;
    string str={};
    int c=0;
    for(int i=0;i<prefrence.length();){
        flag=0;
        str={};
        c=0;
        while(prefrence[i]!='/'&&prefrence[i]!='\0'&&i<prefrence.length()){
            if(prefrence[i]==',') {
                flag = 1;
                i++;
                continue;
            }
            if(!flag){
                str=str+prefrence[i];
            }
            else
                c=c*10+int(prefrence[i])-48;

            i++;
        }

        i++;


        prefrenceNode p;
        p.category= str;
        p.count= c;

        prefrenceVector.push(p);
    }
}

void Users::savePrefrenceVector() {
    prefrence.clear();  // Clear the existing preference string
    for (const auto& p : prefrenceVector) {
        prefrence += p.category + ',' + std::to_string(p.count);
        if (!prefrence.empty()) {
            prefrence += '/';  // Add delimiter between entries
        }

    }
}

customVector<Article> Users::filterBySource(const string& source){
        customVector<Article> filtered;
        customVector<Article> articles = Article::getArticles();
        for (size_t i = 0; i < articles.size(); ++i) {
            if (articles[i].getSource() == source) {
                filtered.push(articles[i]);
            }
        }
        return filtered;
}

customVector<Article> Users::filterByAuthor(const string& Author){
    customVector<Article> filtered;
    customVector<Article> articles = Article::getArticles();
    for (size_t i = 0; i < articles.size(); ++i) {
        if (articles[i].getAuthor() == Author) {
            filtered.push(articles[i]);
        }
    }
    return filtered;
}

customVector<Article> Users::filterByCategory(const string& cat){
    customVector<Article> filtered;
    customVector<Article> articles = Article::getArticles();
    for (size_t i = 0; i < articles.size(); ++i) {
        if (articles[i].getCategory() == cat) {
            filtered.push(articles[i]);
        }
    }
    return filtered;
}

void Users::buildHeap(){
    customVector<Article>& articles = Article::getArticles();

    for (size_t i = 0; i < articles.size(); ++i){
        heapOfPrefrences.insert(maxHeapNode(&articles[i], calcScore(articles[i])));
    }
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

void Users::likeArticle(maxHeapNode& node){
    node.relevancepoints += 0.1;
    // el mafrod ne3ml vector feh el preference w law 3aml like l article msh fe el preference hazwd el category bta3tha fe el preference
}

void Users::dislikeArticle(maxHeapNode& node){
    node.relevancepoints -= 0.1;
}

void Users::notInterested(maxHeapNode& node){
    node.relevancepoints = 0;
    // hashel el category bta3t el article de mn el prefrence vector bta3 el user
}



