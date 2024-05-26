*	User’s manual:
*	Function description: -
1)	Login: Users can log in to the system by entering their username and password.
2)	Registration: Admins and users can register new user accounts by providing a username and password.
3)	Article Management: Admins and users can add new articles to the system, specifying details like title, content, category, source, author, and publication date.
4)	Preference Management: Users can like, or dislike articles based on their preferences, and the system will recommend articles accordingly.
5)	Article Display: Users can view articles filtered by their preferences, category, and type.
6)	Logout/Exit: Users and admins can log out of the system or exit the application.



*	User manual: -
1)	Login/Registration:
o	Upon launching the application, users are prompted to log in with their username and password. If they do not have an account, admins can register new users.
2)	Article and users Management:
o	Admins can add new articles to the system by providing details like title, content, category, source, author, and publication date and they also can register and remove users.
3)	Preference Management:
o	Users can like or dislike articles based on their preferences, and the system will recommend articles accordingly.
4)	Article Display and post:
o	Users can view articles filtered by their preferences, category, author, or source and publish new posts.
5)	Logout/Exit:
o	Users and admins can log out of the system or exit the application when done.


*	How to run:
There are two interfaces to this application

*	Consol:
•	And this doesn’t contain all the features and we can run it using only the main and the classes and functionalities.
*	GUI:
•	In GUI we used Qt Creator 6.7.0 and while setting it up chose desktop development.
•	Open a new project and put all the classes (Accounts, Article, customVector, MaxHeap) in the project (don’t put the main and functionalities) 
•	Put all the files in the GUI_QT6 in the project (don’t take the CMakeLists)
•	From CMakeLists take 

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets TextToSpeech Multimedia MultimediaWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets TextToSpeech)


And


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
	    json.h
        Accounts.cpp
        Accounts.h
        Users.cpp
        Admins.cpp
        MaxHeap.h
        Date.h
        Date.cpp
        MaxHeap.cpp
        Article.cpp
        customVector.h
        adminform.h
        adminform.cpp
        adminform.ui
        Article.h
        userform.h
        userform.cpp
        userform.ui
	    post.ui
	    post.h
	    post.cpp
)

And


find_package(Qt6 COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets TextToSpeech REQUIRED)

# Add the executable

# Include the directories for Qt
include_directories(${Qt6Core_INCLUDE_DIRS} ${Qt6Gui_INCLUDE_DIRS} ${Qt6Widgets_INCLUDE_DIRS} ${Qt6Multimedia_INCLUDE_DIRS} ${Qt6MultimediaWidgets_INCLUDE_DIRS})

target_link_libraries(“YOUR PROJECT NAME” PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::MultimediaWidgets Qt${QT_VERSION_MAJOR}::TextToSpeech)


replace “YOUR PROJECT NAME”  with your’s


•	Take all the three JSON files and bro.ico from cmake-build-debug directory and put it with the .exe
•	Take the Video directory from GUI_QT>Release and put it with the Dsa_gui.exe file.



*	If you want to run the application without doing all of these steps just go to GUI_QT>Release and run the Dsa_gui.exe file
