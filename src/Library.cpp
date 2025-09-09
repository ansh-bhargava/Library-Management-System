#include "Library.h"
#include <iostream>
void Library::displayAllBooks() {
    try {
        std::vector<Book> allBooks = bookRepo.findAll();
        std::cout << "\n--- Library Book Collection (from MySQL) ---" << std::endl;
        for (const auto& book : allBooks) {
            book.display();
        }
        std::cout << "------------------------------------------" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
