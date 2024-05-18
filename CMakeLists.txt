cmake_minimum_required(VERSION 3.27)  # Ensure compatibility with CMake 3.27 or later

project(Customized_News_Feed_Algorithm)  # Project name

set(CMAKE_CXX_STANDARD 14)  # Set C++ standard to 14

# Declare and fetch external dependencies
include(FetchContent)  # Include FetchContent for managing dependencies
FetchContent_Declare(  # Declare the nlohmann/json dependency
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)  # Make the dependency available

# Define the target executable and the files to include
add_executable(
        Customized_News_Feed_Algorithm  # Executable name
        main.cpp  # Source files
        BinarySearchTree.h
        MaxHeap.h
        Date.h
        Date.cpp
        Accounts.h
        Accounts.cpp
        Users.cpp
        Admins.cpp
        MaxHeap.cpp
        Article.cpp
        BinarySearchTree.cpp
        customVector.h
        customSingleLinkedList.h
        functionalities.h
        functionalities.cpp
)

# Link external libraries to the executable
target_link_libraries(
        Customized_News_Feed_Algorithm  # Target executable
        PRIVATE  # Scope is private to this target
        nlohmann_json::nlohmann_json  # Library to link
        winmm  # Link against the Winmm library
)
