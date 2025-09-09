#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book {
public:
    int bookId;
    std::string title;
    std::string author;
    bool isAvailable;
    Book(int id, std::string title, std::string author);
    void display() const;
};
#endif
