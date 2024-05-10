//
// Created by tarek on 5/9/2024.
//

#include "Article.h"

singleLinkedList<Article> Article::articles=singleLinkedList<Article>();

Article::Article(): title(""), content(""), category(""), source(""), author(""), publicationDate(0,0,0) {}
Article::Article(const string& title, const string& content, const string& category, const string& source, const string& author, Date publicationDate): title(title), content(content), category(category), source(source), author(author), publicationDate(publicationDate) {}

string Article::getTitle() const { return title; }
string Article::getContent() const { return content; }
string Article::getCategory() const { return category; }
string Article::getSource() const { return source; }
string Article::getAuthor() const { return author; }
Date Article::getPublicationDate() const { return publicationDate; }
singleLinkedList<Article>& Article::getArticles(){return articles;}

void Article::setTitle(const string& t) { this->title = t; }
void Article::setContent(const string& co) { this->content = co; }
void Article::setCategory(const string& ca) { this->category = ca; }
void Article::setSource(const string& s) { this->source = s; }
void Article::setAuthor(const string& a) { this->author = a; }
void Article::setPublicationDate(const Date& p) { this->publicationDate = p; }

bool Article::saveArticles() {
    ofstream file("articles.json");

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json output;


    // Add new articles to the existing JSON array
    for (sllnode<Article>* temp=articles.getHead(); temp!=nullptr; temp=temp->next) {
        nlohmann::json jsonObj;
        jsonObj["title"] = temp->info.title;
        jsonObj["content"] = temp->info.content;
        jsonObj["category"] = temp->info.category;
        jsonObj["source"] = temp->info.source;
        jsonObj["author"] = temp->info.author;
        jsonObj["publicationDate"] = temp->info.publicationDate.getDate();
        output.push_back(jsonObj);  // Append the new article to the JSON array
    }

    file << setw(4) << output;
    file.close();

    return true;
}

bool Article::loadArticles() {
    articles.clear();

    ifstream file("articles.json");

    if (!file.is_open()) {//making sure books.json was opened successfully
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json jsonArray;
    file >> jsonArray;

    for (const auto& jsonObj : jsonArray) {
        string title = jsonObj["title"];
        string content = jsonObj["content"];
        string category = jsonObj["category"];
        string source = jsonObj["source"];
        string author = jsonObj["author"];
        string publicationDate = jsonObj["publicationDate"];

        articles.addToTail(Article(title, content, category, source, author, publicationDate));
    }
    file.close();

    return true;
}

Article Article::search(Article a) {
    for (sllnode<Article>* temp=articles.getHead(); temp!=nullptr; temp=temp->next) {
        if (temp->info == a) {
            return temp->info;
        }
    }
    throw runtime_error("Article not found");
}

/*vector<Article> Article::filterBySource(const vector<Article>& articles, const string& source) {
    vector<Article> filtered;
    for (const auto& article : articles) {
        if (article.source == source) {
            filtered.push_back(article);
        }
    }
    return filtered;
}*/

bool Article::operator ==(Article other){
    if(this->getTitle() == other.getTitle()&&this->getAuthor() == other.getAuthor()&&this->getCategory() == other.getCategory()&&this->getContent() == other.getContent()&&this->getPublicationDate() == other.getPublicationDate()&&this->getSource() == other.getSource())
        return true;
    else
        return false;
}

bool Article::operator !=(Article other){
    if(this->getTitle() != other.getTitle()&&this->getAuthor() != other.getAuthor()&&this->getCategory() != other.getCategory()&&this->getContent() != other.getContent()&&!(this->getPublicationDate() == other.getPublicationDate())&&this->getSource() != other.getSource())
        return true;
    else
        return false;
}

template<typename T>
sllnode<T>::sllnode(){
    next =0;
}

template<typename T>
sllnode<T>::sllnode(T i){
    info=i;
    next=0;
}

template<typename T>
sllnode<T>::sllnode(T i, sllnode* n){
    info=i;
    next=n;
}

template<typename T>
singleLinkedList<T>::singleLinkedList(){
    head=tail=0;
}

template<typename T>
sllnode<T> *singleLinkedList<T>::getHead() {
    return head;
}

template<typename T>
sllnode<T> *singleLinkedList<T>::getTail() {
    return tail;
}

template<typename T>
bool singleLinkedList<T>::isEmpty(){
    return head==0;
}

template<typename T>
void singleLinkedList<T>::addToHead(T el){
    head=new sllnode<T>(el, head);
    if (tail==0)
        tail=head;
}

template<typename T>
void singleLinkedList<T>::addToTail(T el){
    if (isEmpty())
        head=tail=new sllnode<T>(el);
    else {
        tail->next=new sllnode<T>(el);
        tail=tail->next;
    }
}

template<typename T>
T singleLinkedList<T>::deleteFromHead() {
    if(!isEmpty()){
        T el=head->info;
        if (head == tail){
            delete head;
            head=tail=0;
        }
        else{
            sllnode<T>* temp=head;
            head=head->next;
            delete temp;
        }
        return el;
    }
    else
        cout<< "the list is empty";
    return NULL;
}

template<typename T>
T singleLinkedList<T>::deleteFromTail(){
    if(!isEmpty()){
        T el=tail->info;
        if (head == tail){
            delete tail;
            head=tail=0;
        }
        else{
            sllnode<T>* temp;
            for(temp=head;temp->next!=tail;temp=temp->next);
            tail=temp;
            temp=temp->next;
            delete temp;
            tail->next=0;
        }
        return el;
    }
    else
        cout<< "the list is empty";
    return NULL;
}

template<typename T>
void singleLinkedList<T>::deletenode(T el){
    if(!isEmpty()){
        if (head->info == el){
            deleteFromHead();
        }
        else if(tail->info == el){
            deleteFromHead();
        }
        else{
            sllnode<T>* temp,*temp2;
            for(temp=head;temp->next->info!=el&&temp->next!=tail;temp=temp->next);
            temp2=temp->next;
            if (temp2!=tail) {
                temp->next = temp->next->next;
                delete temp2;
            }
        }
    }
    else
        cout<< "the list is empty";
}

template<typename T>
bool singleLinkedList<T>::isInList(T el) const{
    sllnode<T>* temp;
    for(temp=head;temp->info!=el&&temp!=tail;temp=temp->next);
    return temp->info==el;
}

template<typename T>
void singleLinkedList<T>::clear() {
    sllnode<T>* p=head;
    while (head!=0){
        p=p->next;
        delete head;
        head=p;
    }
    head=tail=0;
}

template<typename T>
singleLinkedList<T>::~singleLinkedList(){
    sllnode<T>* p=head;
    while (head!=0){
        p=p->next;
        delete head;
        head=p;
    }
    head=tail=0;
}