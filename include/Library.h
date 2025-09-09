#ifndef LIBRARY_H
#define LIBRARY_H
#include "BookRepository.h"
class Library {
private:
    BookRepository bookRepo;
public:
    void displayAllBooks();
    // Add other methods like checkoutBook, etc.
};
#endif
