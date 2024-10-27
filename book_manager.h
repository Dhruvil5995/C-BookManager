#ifndef BOOK_MANAGER_H
#define BOOK_MANAGER_H

#include <string>

struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
};

// Function declarations
void addBook(int id, const std::string& title, const std::string& author, int year);
void viewBooks();
void deleteBook(int id);


#endif
