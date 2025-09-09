#include "Library.h"
#include <iostream>
int main() {
    try {
        Library myLibrary;
        std::cout << "Welcome to the Library Management System!" << std::endl;
        myLibrary.displayAllBooks();
        // Here you would add a menu for user interaction
    } catch (const std::exception& e) {
        std::cerr << "Application failed to start: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
