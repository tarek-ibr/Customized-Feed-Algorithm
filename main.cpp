#include <iostream>
#include "Article.h"
#include "Accounts.h"
#include "functionalities.h"



int main() {
    Article::loadArticles();
    Admins::loadAdmin();
    Users::loadUsers();

    customVector<Article>& articles = Article::getArticles();
    customVector<Admins>& admins = Admins::getAdmins();
    customVector<Users>& users = Users::getUsers();

    // Example: User interaction
    if (!users.empty()) {
        Users& user = users[0];
        user.setPrefrence("Technology");

        // Display news feed for the user
        std::cout << "User news feed for preference '" << user.getPrefrence() << "':" << std::endl;
        displayNewsFeed(user);

        // User menu
        userMenu();
    }

    // Example: Admin interaction
    if (!admins.empty()) {
        Admins& admin = admins[0];

        // Admin menu
        adminMenu();

    }

    // Save data back to files
    Admins::saveAdmins();
    Users::saveUsers();
    Article::saveArticles();

    return 0;
}