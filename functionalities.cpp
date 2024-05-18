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



void adminMenu() {



    while (true) {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Article\n";
        cout << "2. Delete Article\n";
        cout << "3. View Articles\n";
        cout << "4. Manage Users\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                //addNewArticle();
                break;
            }
            case 2: {/*
                cout << "Enter the title of the article to delete: ";
                string title;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                getline(cin, title);
                if (Article::deleteArticle(title)) {
                    cout << "Article deleted successfully!\n";
                } else {
                    cout << "Article not found!\n";
                }*/
                break;
            }
            case 3: {
                cout << "Articles:\n";
                //Article::displayArticles();
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                cout << "Logged out successfully.\n";
                return;
            }
            default: {
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
                break;
            }
        }
    }
}

void userMenu() {
    while (true) {
        cout << "\nUser Menu:\n";
        cout << "1. View Articles\n";
        cout << "2. Filter Articles by Category\n";
        cout << "3. Filter Articles by Author\n";
        cout << "4. Filter Articles by Source\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Articles:\n";
                //Article::displayArticles();
                break;
            }
            case 2: {/*
                string category;
                cout << "Enter category to filter: ";
                cin >> category;
                customVector<Article> filtered = Users::filterByCategory(category);
                cout << "Filtered Articles:\n";
                for (size_t i = 0; i < filtered.size(); ++i) {
                    cout << filtered[i].getTitle() << endl;
                }*/
                break;
            }
            case 3: {/*
                string author;
                cout << "Enter author to filter: ";
                cin >> author;
                customVector<Article> filtered = Users::filterByAuthor(author);
                cout << "Filtered Articles:\n";
                for (size_t i = 0; i < filtered.size(); ++i) {
                    cout << filtered[i].getTitle() << endl;
                }*/
                break;
            }
            case 4: {/*
                string source;
                cout << "Enter source to filter: ";
                cin >> source;
                customVector<Article> filtered = Users::filterBySource(source);
                cout << "Filtered Articles:\n";
                for (size_t i = 0; i < filtered.size(); ++i) {
                    cout << filtered[i].getTitle() << endl;
                }*/
                break;
            }
            case 5: {
                cout << "Logged out successfully.\n";
                return;
            }
            default: {
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
                break;
            }
        }
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


void displayArticle(const Article& article) {
    cout << "Title: " << article.getTitle() << endl;
    cout << "Author: " << article.getAuthor() << endl;
    cout << "Category: " << article.getCategory() << endl;
    cout << "Content: " << article.getContent() << endl;
    cout << "Source: " << article.getSource() << endl;
    cout << "Publication Date: " << article.getPublicationDate().getDate() << endl;
}


void userInteraction(Users& user){
    //user.buildHeap();

    while (!user.heapOfPrefrences.isEmpty()) {
        maxHeapNode topNode = user.heapOfPrefrences.extract_max();
        const Article* article = topNode.article;

        displayArticle(*article);

        cout << "\nActions: [1] Like [2] Dislike [3] Next Article [4] Exit\n";
        cout << "Choose an action: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                //user.likeArticle(topNode);
                cout << "Article liked.\n";
                break;
            case 2:
                //user.dislikeArticle(topNode);
                cout << "Article disliked.\n";
                break;
            case 3:
                continue;
            case 4:
                return;
            default:
                cout << "Invalid choice.\n";
        }

    }
    cout << "No more articles.\n";
}


