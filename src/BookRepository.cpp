#include "BookRepository.h"
#include <stdexcept>
BookRepository::BookRepository() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        // Replace with your database credentials
        con.reset(driver->connect("tcp://127.0.0.1:3306", "user", "password"));
        con->setSchema("library_db");
    } catch (sql::SQLException &e) {
        throw std::runtime_error("Could not connect to database.");
    }
}
Book BookRepository::findById(int bookId) {
    // Implementation to find a book by its ID from the DB
    // ...
    return Book(0, "", ""); // Placeholder
}
std::vector<Book> BookRepository::findAll() {
    std::vector<Book> books;
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM books"));
    while (res->next()) {
        Book book(res->getInt("book_id"), res->getString("title"), res->getString("author"));
        book.isAvailable = res->getBoolean("is_available");
        books.push_back(book);
    }
    return books;
}
void BookRepository::save(const Book& book) {
    // Implementation to INSERT or UPDATE a book in the DB
    // ...
}
