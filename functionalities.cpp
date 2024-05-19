//
// Created by tarek on 5/18/2024.
//


#include "functionalities.h"

using namespace std;

void loadFiles(){
    Article::loadArticles();
    Admins::loadAdmin();
    Users::loadUsers();
}

void saveFiles(){
    Admins::saveAdmins();
    Users::saveUsers();
    Article::saveArticles();
}

string login(string username, string password){
    // Check if the credentials match any admin account
    for (size_t i = 0; i < Admins::getAdmins().size(); ++i) {
        if (Admins::getAdmins()[i].getusername() == username && Admins::getAdmins()[i].getpassword() == password) {
            return "admin";
        }
    }

    // Check if the credentials match any user account
    for (size_t i = 0; i < Users::getUsers().size(); ++i) {
        if (Users::getUsers()[i].getusername() == username && Users::getUsers()[i].getpassword() == password) {
            return "user";
        }
    }
    return "invalid";
}

void implementAdminChoice(Admins& admin, int choice){

    switch (choice) {
        case 1: {
            // Prompt the user to enter their username
            cout << "Enter your username: ";
            string username;
            cin >> username;

            // Prompt the user to enter their password
            cout << "Enter your password: ";
            string password;
            cin >> password;
            admin.registerNewUser(username, password);
            break;
        }
        case 2: {
            // Prompt the user to enter their username
            cout << "Enter your username: ";
            string username;
            cin >> username;

            admin.removeUser(username);
            break;
        }
        case 3: {
            string title, content, category, source, author;
            Date publicationDate;

            cout << "Enter article title: ";
            getline(cin, title);

            cout << "Enter article content: ";
            getline(cin, content);

            cout << "Enter article category: ";
            getline(cin, category);

            cout << "Enter article source: ";
            getline(cin, source);

            cout << "Enter article author: ";
            getline(cin, author);

            cout << "Enter publication date (DD/MM/YYYY): ";
            string dateStr;
            getline(cin, dateStr);
            Date date(dateStr);

            Article newArticle(title, content, category, source, author, date);
            admin.addArticle(newArticle);
            break;
        }
        default:
            break;

    }
}

void implementUserChoice(Users& user, int choice, Article& currentArticle){
    switch (choice) {
        case 1: {
            user.likeArticle(currentArticle.getCategory());
            break;
        }
        case 2: {
            currentArticle = user.getArticle();
            break;
        }
        default:
            break;

    }
}


void displayNewsFeed(Users& user) {
    customVector<Article> filteredArticles = user.filterByCategory(user.getPrefrence());

    for (const Article& article: filteredArticles) {
        cout << "Title: " << article.getTitle() << endl;
        cout << "Content: " << article.getContent() << endl;
        cout << "Source: " << article.getSource() << endl;
        cout << "Author: " << article.getAuthor() << endl;
        cout << "Publication Date: " << article.getPublicationDate().getDate() << endl;
        cout << endl;
    }
}

