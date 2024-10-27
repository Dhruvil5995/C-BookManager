#include <iostream>
#include "book_manager.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "\n--- Book Manager ---\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Delete Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, year;
            string title, author;
            cout << "Enter book ID: ";
            cin >> id;
            cin.ignore(); // Ignore newline character in buffer
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            addBook(id, title, author, year);
        } else if (choice == 2) {
            viewBooks();
        } else if (choice == 3) {
            int id;
            cout << "Enter book ID to delete: ";
            cin >> id;
            deleteBook(id);
        }
    } while (choice != 4);

    cout << "Exiting the program. Goodbye!\n";
    return 0;
}
