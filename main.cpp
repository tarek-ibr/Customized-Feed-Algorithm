#include <iostream>
#include "Article.h"
#include "Accounts.h"
#include "functionalities.h"

void displayArticle(const Article& article) {
    cout << "Title: " << article.getTitle() << endl;
    cout << "Author: " << article.getAuthor() << endl;
    cout << "Category: " << article.getCategory() << endl;
    cout << "Content: " << article.getContent() << endl;
    cout << "Source: " << article.getSource() << endl;
    cout << "Publication Date: " << article.getPublicationDate().getDate() << endl;
}

void userInteraction(Users& user){
    user.buildHeap();

    while (!user.heapOfPrefrences.isEmpty()) {
        maxHeapNode topNode = user.heapOfPrefrences.extract_max();
        const Article* article = topNode.article;

        cout << "\nArticle Relevance Score: " << topNode.relevancepoints << endl;
        displayArticle(*article);

        cout << "\nActions: [1] Like [2] Dislike [3] Next Article [4] Exit\n";
        cout << "Choose an action: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                user.likeArticle(topNode);
                cout << "Article liked.\n";
                break;
            case 2:
                user.dislikeArticle(topNode);
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



int main() {

    Article::loadArticles();
    Admins::loadAdmin();
    Users::loadUsers();


    customVector<Article>& s1 = Article::getArticles();
    customVector<Admins>& a1 = Admins::getAdmins();
    customVector<Users>& u1 = Users::getUsers();


    cout<<a1[0].getusername()<<endl;

    cout<<u1[0].getusername()<<endl;

    cout<<s1[0].getTitle()<<endl;


    displayNewsFeed(u1[0]);


    Article::saveArticles();
    Admins::saveAdmins();
    Users::saveUsers();

    system("pause");

    return 0;
}

