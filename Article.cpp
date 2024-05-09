//
// Created by tarek on 5/9/2024.
//

#include "Article.h"

singleLinkedList<Article> Article::articles=singleLinkedList<Article>();

Article::Article(const string& title, const string& content, const string& category, const string& source, const string& author, Date publicationDate): title(title), content(content), category(category), source(source), author(author), publicationDate(publicationDate) {}

string Article::getTitle() const { return title; }
string Article::getContent() const { return content; }
string Article::getCategory() const { return category; }
string Article::getSource() const { return source; }
string Article::getAuthor() const { return author; }
Date Article::getPublicationDate() const { return publicationDate; }
singleLinkedList<Article>& Article::getArticles(){return articles;}

void Article::setTitle(const string& title) { this->title = title; }
void Article::setContent(const string& content) { this->content = content; }
void Article::setCategory(const string& category) { this->category = category; }
void Article::setSource(const string& source) { this->source = source; }
void Article::setAuthor(const string& author) { this->author = author; }
void Article::setPublicationDate(const Date& publicationDate) { this->publicationDate = publicationDate; }

bool Article::saveArticles() {
    ofstream file("articles.json");

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return false;
    }

    nlohmann::json output;


    // Add new articles to the existing JSON array
    for (sllnode<Article>* temp=articles.getHead(); temp!=NULL; temp=temp->next) {
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

Article Article::searchByTitle(const vector<Article>& articles, const string& title) {
    for (const auto& article : articles) {
        if (article.title == title) {
            return article;
        }
    }
    throw runtime_error("Article not found");
}

vector<Article> Article::filterBySource(const vector<Article>& articles, const string& source) {
    vector<Article> filtered;
    for (const auto& article : articles) {
        if (article.source == source) {
            filtered.push_back(article);
        }
    }
    return filtered;
}