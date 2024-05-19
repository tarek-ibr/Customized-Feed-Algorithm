//
// Created by tarek on 5/9/2024.
//

#include "Article.h"

customVector<Article> Article::articles=customVector<Article>();

Article::Article(): title(""), content(""), category(""), source(""), author(""), publicationDate(0,0,0) {}
Article::Article(const string& title, const string& content, const string& category, const string& source, const string& author, Date publicationDate): title(title), content(content), category(category), source(source), author(author), publicationDate(publicationDate) {}

string Article::getTitle() const { return title; }
string Article::getContent() const { return content; }
string Article::getCategory() const { return category; }
string Article::getSource() const { return source; }
string Article::getAuthor() const { return author; }
Date Article::getPublicationDate() const { return publicationDate; }
customVector<Article>& Article::getArticles(){return articles;}

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
    for (size_t i=0;i<articles.size();i++) {
        nlohmann::json jsonObj;
        jsonObj["title"] = articles[i].title;
        jsonObj["content"] = articles[i].content;
        jsonObj["category"] = articles[i].category;
        jsonObj["source"] = articles[i].source;
        jsonObj["author"] = articles[i].author;
        jsonObj["publicationDate"] = articles[i].publicationDate.getDate();
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

        articles.push(Article(title, content, category, source, author, publicationDate));
    }
    file.close();

    return true;
}

void Article::displayArticle() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Category: " << category << endl;
    cout << "Source: " << source << endl;
    cout << "Publication Date: " << publicationDate.getDate() << endl;
    cout << "Content: " << content << endl;
}

Article Article::search(Article a) {
    for (size_t i=0;i<articles.size();i++) {
        if (articles[i] == a) {
            return articles[i];
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
