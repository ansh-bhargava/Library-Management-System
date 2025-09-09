#ifndef BOOK_REPOSITORY_H
#define BOOK_REPOSITORY_H
#include "Book.h"
#include <vector>
#include <memory>
#include <mysql-cppconn/jdbc/mysql_driver.h>
#include <mysql-cppconn/jdbc/mysql_connection.hh>
#include <mysql-cppconn/jdbc/cppconn/statement.h>
#include <mysql-cppconn/jdbc/cppconn/resultset.h>
class BookRepository {
private:
    std::unique_ptr<sql::Connection> con;
public:
    BookRepository();
    Book findById(int bookId);
    std::vector<Book> findAll();
    void save(const Book& book);
};
#endif
