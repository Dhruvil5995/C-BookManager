#include "book_manager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std; // Using the standard namespace

// Function to add a book
void addBook(int id, const string& title, const string& author, int year) {
    ofstream file("books.txt", ios::app); // Open file in append mode
    if (file.is_open()) {
        file << id << "," << title << "," << author << "," << year << "\n";
        file.close();
        cout << "Book added successfully!\n";
    } else {
        cerr << "Unable to open file.\n";
    }
}

// Function to view all books
void viewBooks() {
    ifstream file("books.txt"); // Open file in read mode
    if (file.is_open()) {
        string line;
        cout << "ID | Title | Author | Year\n";
        while (getline(file, line)) {
            stringstream ss(line);
            string id, title, author, year;

            getline(ss, id, ',');
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, year, ',');

            cout << id << " | " << title << " | " << author << " | " << year << "\n";
        }
        file.close();
    } else {
        cerr << "Unable to open file.\n";
    }
}

// Function to delete a book by ID
void deleteBook(int id) {
    ifstream file("books.txt");
    ofstream tempFile("temp.txt"); // Temporary file to store remaining records

    bool found = false;
    if (file.is_open() && tempFile.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string bookId;
            getline(ss, bookId, ',');

            if (stoi(bookId) != id) {
                tempFile << line << "\n";
            } else {
                found = true;
            }
        }
        file.close();
        tempFile.close();

        remove("books.txt");               // Delete original file
        rename("temp.txt", "books.txt");    // Rename temp file

        if (found) {
            cout << "Book deleted successfully!\n";
        } else {
            cout << "Book not found.\n";
        }
    } else {
        cerr << "Unable to open file.\n";
    }
}
