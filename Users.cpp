//
// Created by tarek on 5/9/2024.
//

#include "Accounts.h"
#include "Article.h"

customVector<Users> Users::users = customVector<Users>();

Users::Users() : Accounts(){}

Users::Users(string u, string pass, string pref, string s) : Accounts(u, pass), prefrence(pref), seen(s){}


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
    float score = 1;
    for(auto& it:prefrenceVector){
        if(it.category==A.getCategory()){
            score=pow(it.count, 0.5);
            break;
        }
    }
    score*=pow(0.95, (Date::getCrrentDate() - A.getPublicationDate()));
    return score;
}

int Users::findByUsername(string username){
    int i=0;
    // Loop through all members
    for(auto& it:users)
    {
        // If the member is found
        if(it.getusername()==username)
        {
            Users* u = &it;
            break;
        }
        i++;
    }

    return i;
}

void Users::loadPrefrenceVector(){
    bool flag=0;
    string str={};
    int c=0;
    prefrenceVector={};
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

void Users::loadSeenVector(){
    string str={};
    seenVector={};
    for(int i=0;i<seen.length();){
        str={};
        while(seen[i]!='/'&&seen[i]!='\0'&&i<seen.length()){
            str+=seen[i];
            i++;
        }
        i++;

        seenVector.push(str);
    }
}

void Users::saveSeenVector(){
    seen.clear();  // Clear the existing preference string
    for (const auto& it : seenVector) {
        seen += it + '/' ;
    }
}

customVector<Article> Users::filterByCategory(string cat){
    customVector<Article> filtered;
    customVector<Article> articles = Article::getArticles();
    for (size_t i = 0; i < articles.size(); ++i) {
        if (articles[i].getCategory() == cat) {
            filtered.push(articles[i]);
        }
    }
    return filtered;
}

customVector<Article> Users::filterByType(string typ){
    customVector<Article> filtered;
    customVector<Article> articles = Article::getArticles();
    for (size_t i = 0; i < articles.size(); ++i) {
        if (articles[i].getType() == typ) {
            filtered.push(articles[i]);
        }
    }
    return filtered;

}

customVector<Article> Users::filterByType(customVector<Article> a, string typ){
    customVector<Article> filtered;
    customVector<Article> articles = a;
    for (size_t i = 0; i < articles.size(); ++i) {
        if (articles[i].getType() == typ) {
            filtered.push(articles[i]);
        }
    }
    return filtered;
}

void Users::buildHeap(customVector<Article>& articles){
    heapOfPrefrences.clear();
    bool flag =false;
    for (size_t i = 0; i < articles.size(); ++i){
        flag=false;
        for(auto& it : seenVector){
            if (articles[i].getContent()==it) {
                flag = true;
                break;
            }
        }
        if (!flag)
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
        jsonObj["seen"] = users[i].seen;

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
        string seen = jsonObj["seen"];

        users.push(Users(username, password, prefrence,seen));
    }
    file.close();

    return true;
}

void Users::likeArticle(string cat){
    bool flag =0;
    for(auto& it:prefrenceVector){
        if(it.category==cat) {
            it.count++;
            flag=1;
        }
    }
    if (!flag){
        prefrenceNode p;
        p.category= cat;
        p.count= 2;

        prefrenceVector.push(p);
    }

}

void Users::notInterested(string cat){
    bool flag =0;
    for(auto& it:prefrenceVector){
        if(it.category==cat) {

            it.count-=20;
            flag=1;
            if (it.count<0)
                it.count=0;
        }
    }

    if (!flag){
        prefrenceNode p;
        p.category= cat;
        p.count= 0;

        prefrenceVector.push(p);
    }
}

void Users::removeLikeArticle(string cat){
    for(auto& it:prefrenceVector){
        if(it.category==cat) {
            it.count--;
        }
    }
}

void Users::removeNotInterested(string cat){
    for(auto& it:prefrenceVector){
        if(it.category==cat) {
            it.count+=10;
        }
    }
}

Article Users::getArticle() {
    if(!heapOfPrefrences.isEmpty()) {
        maxHeapNode n = heapOfPrefrences.extract_max();
        seenVector.push(n.article->getContent());
        return *(n.article);
    }
    else
        return Article();
}

