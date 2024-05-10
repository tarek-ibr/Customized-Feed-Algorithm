/*#include <iostream>
#include "Article.h"
#include "Accounts.h"


int main() {

    Article::loadArticles();
    Admins::loadAdmin();
    Users::loadUsers();


    singleLinkedList<Article>& s1 = Article::getArticles();
    singleLinkedList<Admins>& a1 = Admins::getAdmins();
    singleLinkedList<Users>& u1 = Users::getUsers();


    sllnode<Admins>* a2 = a1.getHead();
    cout<<a2->info.getusername()<<endl;

    sllnode<Users>* u2 = u1.getHead();
    cout<<u2->info.getusername()<<endl;

    sllnode<Article>* s2 = s1.getHead();
    cout<<s2->info.getTitle()<<endl;

    //sllnode* s3 = s1.getTail();
    //cout<<s3->info.getTitle()<<endl;

    //s2->info.setAuthor("eljooker");




    Article::saveArticles();
    Admins::saveAdmins();
    Users::saveUsers();

    system("pause");

    return 0;
}
*/

#include <iostream>
#include "customVector.h"

using namespace std;

int main() {
    customVector<int> v;

    // Test push
    for (int i = 0; i < 10; ++i) {
        v.push(i);
    }
    cout << "After push: ";
    v.print();

    // Test insert
    v.insert(5, 100);
    cout << "After insert: ";
    v.print();

    // Test erase
    v.erase(5);
    cout << "After erase: ";
    v.print();

    // Test operator[]
    cout << "v[5] = " << v[5] << '\n';

    // Test size
    cout << "Size: " << v.size() << '\n';

    // Test empty
    cout << "Empty: " << std::boolalpha << v.empty() << '\n';

    return 0;
}
