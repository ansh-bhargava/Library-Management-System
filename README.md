# C++ Library Management System with MySQL

This is a comprehensive command-line application for managing a library's inventory and member checkouts, built with C++ and integrated with a MySQL database for persistent storage.

The project is designed to showcase core Object-Oriented Programming (OOP) principles and a clean, layered software architecture.

---

## ✨ Features

- **Book Management:** Add new books to the library's database.
- **Member Management:** Register new library members.
- **Checkout/Return System:** Allow members to borrow and return books, with status updates reflected in the database.
- **Persistent Storage:** All data (books, members, borrowings) is stored in a MySQL database.
- **Layered Architecture:** The business logic is decoupled from the data access logic using the Repository design pattern.

---

## 🛠️ Tech Stack

- **Language:** C++17
- **Database:** MySQL
- **Compiler:** g++ / Clang / MSVC
- **Libraries:**
  - C++ Standard Library (STL)
  - MySQL Connector/C++

---

## 🚀 Getting Started

### Prerequisites

Before you begin, ensure you have the following installed:
1.  A C++ compiler (like g++).
2.  MySQL Server.
3.  [MySQL Connector/C++](https://dev.mysql.com/doc/connector-cpp/8.0/en/). You must correctly link this library during compilation.

### Database Setup

1.  Connect to your MySQL server.
2.  Create the database and tables using the following SQL script:

```sql
CREATE DATABASE library_db;
USE library_db;

CREATE TABLE books (
    book_id INT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    author VARCHAR(255),
    is_available BOOLEAN DEFAULT TRUE
);

CREATE TABLE members (
    member_id INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL
);

CREATE TABLE borrowed_books (
    borrow_id INT AUTO_INCREMENT PRIMARY KEY,
    member_id INT,
    book_id INT,
    FOREIGN KEY (member_id) REFERENCES members(member_id),
    FOREIGN KEY (book_id) REFERENCES books(book_id)
);
```

### Build and Run

1.  Clone the repository:
    ```sh
    git clone <your-repo-url>
    cd Library-Management-System
    ```
2.  Compile the project using the provided `Makefile`. You may need to edit the `Makefile` to specify the correct paths for your MySQL Connector/C++ include and library files.
    ```sh
    make
    ```
3.  Run the application:
    ```sh
    ./library_app
    ```

---

## 🏛️ Project Structure

The project is organized into `include` and `src` directories to separate class declarations from their implementations.

```
/
├── include/              # Header files (.h)
│   ├── Book.h
│   ├── Member.h
│   ├── BookRepository.h
│   └── Library.h
├── src/                  # Source files (.cpp)
│   ├── Book.cpp
│   ├── Member.cpp
│   ├── BookRepository.cpp
│   ├── Library.cpp
│   └── main.cpp
├── .gitignore
├── Makefile
└── README.md
```

---

## 🧠 OOP Concepts Demonstrated

- **Encapsulation:** Data members are private, and access is controlled through public methods.
- **Inheritance:** (Can be extended) A base `LibraryItem` class can be used to derive `Book`, `Magazine`, etc.
- **Polymorphism:** (Can be extended) Virtual functions in `LibraryItem` would allow treating different item types uniformly.
- **Abstraction:** The `Library` class provides a simple interface (`checkoutBook`, etc.) that hides the complex underlying database interactions.
- **Separation of Concerns:** The **Repository Pattern** is used to create a Data Access Layer (`BookRepository`), cleanly separating the business logic (`Library`) from the database logic.
