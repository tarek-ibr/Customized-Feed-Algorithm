#ifdef _WIN32
#  ifdef USE_ASIO
//     Set the proper SDK version before including boost/Asio
#      include <SDKDDKVer.h>
//     Note boost/ASIO includes Windows.h.
#      include <boost/asio.hpp>
#   else //  USE_ASIO
#      include <Windows.h>
#   endif //  USE_ASIO
#else // _WIN32
#  ifdef USE_ASIO
#     include <boost/asio.hpp>
#  endif // USE_ASIO
#endif //_WIN32

// Include necessary libraries and files
#include <iostream>
#include <fstream>
#include <vector>
#include "Article.h"
#include "Accounts.h"
#include "Functionalities.h"
#include "playsoundapi.h"
#include <thread>

using namespace std;
using json = nlohmann::json;

// Get the standard output handle
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Function declarations
void displayCompanyName();
void displayAdminMenu();
void displayUserMenu();
void playSound(const char* wavPath);

// Main function
int main() {
    // Path to the sound file
    const char* wavPath = "music.wav";

    // Start a new thread to play the sound
    std::thread soundThread(playSound, wavPath);

    // Set the console size
    cout << "\e[8;200;150t";

    // Login label for goto statement
    Login:

    // Display the library name
    displayCompanyName();

    // Load the files
    loadFiles();

    // Set the console text attribute
    SetConsoleTextAttribute(hConsole, 8);

    // Prompt the user to enter their username
    cout<<"Enter your username: ";
    string username;
    cin>>username;

    // Prompt the user to enter their password
    cout<<"Enter your password: ";
    string password;
    cin>>password;

    // Clear the console
    system("cls");

    // Login with the entered ID
    string type = login(username, password);

    // Set the console text attribute
    SetConsoleTextAttribute(hConsole, 3);

    // If the user is a member
    if(type=="user"){
        // Find the member by ID
        customVector<Users>& users = Users::getUsers();
        Users& user=users[Users::findByUsername(username)];
        int flag=0;

        user.loadPrefrenceVector();
        user.loadSeenVector();
        user.buildHeap(Article::getArticles());

        Article currentArticle = user.getArticle();

        // Infinite loop for the member menu
        while(true){

            // Display the library name
            displayCompanyName();

            // Welcome the member
            cout<<endl <<"\t\t\t\t\t\t\tWelcome " <<user.getusername() <<" to our newspaper " <<endl;
            if (currentArticle ==Article()){
                cout<<"you have finished all the articles";
                break;
            }
            currentArticle.displayArticle();

            cout<<endl<<endl;
            displayUserMenu();

            // Prompt the user to choose an option
            int userOption;
            Member_Choose_Option:
            cin.ignore();
            cin>>userOption;

            if(userOption==1&&flag==1)
                goto Member_Choose_Option;
            else
                flag=0;

            if(userOption==1){
                implementUserChoice(user, userOption, currentArticle);
                user.savePrefrenceVector();
                user.saveSeenVector();
                user.buildHeap(Article::getArticles());
                flag=1;
                goto Member_Choose_Option;
            }
            else if(userOption==2){
                implementUserChoice(user, userOption, currentArticle);
                user.savePrefrenceVector();
                user.saveSeenVector();
                user.buildHeap(Article::getArticles());
                implementUserChoice(user, 3, currentArticle);
                user.saveSeenVector();
            }
            else if(userOption==3){
                implementUserChoice(user, userOption, currentArticle);
                user.saveSeenVector();
            }
            // If the user chooses to logout
            else if(userOption==4) {
                // Save the files
                user.saveSeenVector();
                saveFiles();

                // Clear the console
                system("cls");

                // Go to the login label
                goto Login;
            }
                // If the user chooses to exit
            else if(userOption==5) {
                user.saveSeenVector();
                break;
            }
                // If the user enters an invalid choice
            else if (userOption <1 || userOption > 5){
                cout<<"Invalid choice" <<endl;
                goto Member_Choose_Option;
            }



            // Clear the console
            system("cls");
        }
    }
        // If the user is a librarian
    else if(type=="admin"){
        // Find the librarian by ID
        Admins admin = Admins::findByUsername(username);

        // Infinite loop for the librarian menu
        while(true){

            // Display the library name
            displayCompanyName();

            // Welcome the librarian
            cout<<endl <<"\t\t\t\t\t\t\tWelcome back " <<admin.getusername() <<endl;

            // Display the librarian menu
            displayAdminMenu();

            // Prompt the user to choose an option
            int adminOption;
            Admin_Choose_Option:
            cin >> adminOption;

            // If the user chooses to logout
            if (adminOption == 4) {
                // Save the files
                saveFiles();

                // Clear the console
                system("cls");

                // Go to the login label
                goto Login;
            }
                // If the user chooses to exit
            else if (adminOption == 5) {
                break;
            }
                // If the user enters an invalid choice
            else if (adminOption <1 || adminOption > 5){
                cout<<"Invalid choice" <<endl;
                goto Admin_Choose_Option;
            }

            // Clear the console
            system("cls");

            // Implement the chosen option
            implementAdminChoice(admin, adminOption);

            // Pause the console
            system("pause");

            // Clear the console
            system("cls");
        }
    }
        // If the user is not found
    else if(type=="invalid"){
        cout<<"You are not registered in our system, Please check your username or password again!!"<<endl<<endl;
        system("pause");
        goto Login;
    }

    // Save the files
    saveFiles();

    // Pause the console
    system("pause");

    // Join the sound thread
    soundThread.join();

    return 0;
}

// Function to display the library name
void displayCompanyName(){
    SetConsoleTextAttribute(hConsole, 6);
    

    cout<<"\t\t\t    ________         ___   _____ ____  ____    ___    ___    _   _________       _______ ____  ___    ____  __________ \n"
          "\t\t\t   / ____/ /        /   | / ___// __ \\/ __ \\  /   |  /   |  / | / / ____/ |     / / ___// __ \\/   |  / __ \\/ ____/ __ \\\n"
          "\t\t\t  / __/ / /  ______/ /| | \\__ \\/ / / / / / / / /| | / /| | /  |/ / __/  | | /| / /\\__ \\/ /_/ / /| | / /_/ / __/ / /_/ /\n"
          "\t\t\t / /___/ /__/_____/ ___ |___/ / /_/ / /_/ / / ___ |/ ___ |/ /|  / /___  | |/ |/ /___/ / ____/ ___ |/ ____/ /___/ _, _/ \n"
          "\t\t\t/_____/_____/    /_/  |_/____/_____/\\___\\_\\/_/  |_/_/  |_/_/ |_/_____/  |__/|__//____/_/   /_/  |_/_/   /_____/_/ |_|  ";
    cout<<"\n\n\n";
}




void displayAdminMenu() {
    cout << "Admin Menu:" << endl;
    cout << "1. Add Member" << endl;
    cout << "2. Remove Member" << endl;
    cout << "3. Add Article" << endl;
    cout << "4. logout" << endl;
    cout << "5. Exit" << endl;
}

void displayUserMenu() {
    cout << "User Menu:" << endl;
    cout << "1. Like" << endl;
    cout << "2. Not interested" << endl;
    cout << "3. Next article" << endl;
    cout << "4. logout" << endl;
    cout << "5. Exit" << endl;
}

// Function to play a sound
void playSound(const char* wavPath) {
    PlaySoundA(wavPath, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
