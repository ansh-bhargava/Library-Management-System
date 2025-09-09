#include "Book.h"
#include <iostream>
Book::Book(int id, std::string t, std::string a)
    : bookId(id), title(std::move(t)), author(std::move(a)), isAvailable(true) {}
void Book::display() const {
    std::cout << "ID: " << bookId << ", Title: \"" << title
              << "\", Author: " << author
              << ", Status: " << (isAvailable ? "Available" : "Checked Out") << std::endl;
}
