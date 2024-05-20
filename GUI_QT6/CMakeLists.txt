cmake_minimum_required(VERSION 3.5)

project(dsa_gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

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
    BinarySearchTree.h
    MaxHeap.h
    Date.h
    Date.cpp
    MaxHeap.cpp
    Article.cpp
    BinarySearchTree.cpp
    customVector.h
    customSingleLinkedList.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(dsa_gui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        adminform.h adminform.cpp adminform.ui
        Article.h
        userform.h userform.cpp userform.ui
        rsrcs.qrc


    )
else()
    if(ANDROID)
        add_library(dsa_gui SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(dsa_gui
            ${PROJECT_SOURCES}
        )
    endif()
endif()

find_package(Qt6 COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets REQUIRED)

# Add the executable

# Include the directories for Qt
include_directories(${Qt6Core_INCLUDE_DIRS} ${Qt6Gui_INCLUDE_DIRS} ${Qt6Widgets_INCLUDE_DIRS} ${Qt6Multimedia_INCLUDE_DIRS} ${Qt6MultimediaWidgets_INCLUDE_DIRS})

target_link_libraries(dsa_gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::MultimediaWidgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.dsa_gui)
endif()
set_target_properties(dsa_gui PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS dsa_gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(dsa_gui)
endif()
