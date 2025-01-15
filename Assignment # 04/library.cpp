#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book {
    string bookId;
    string title;
    string author;
    int quantity;
};

Book books[100];
int bookCount = 0;

void saveToFile() {
    ofstream file("library.txt", ios::out);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        file << books[i].bookId << endl
             << books[i].title << endl
             << books[i].author << endl
             << books[i].quantity << endl;
    }

    file.close();
    cout << "Library data saved successfully." << endl;
}

void loadFromFile() {
    ifstream file("library.txt", ios::in);
    if (!file) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    while (file >> books[bookCount].bookId) {
        file.ignore();
        getline(file, books[bookCount].title);
        getline(file, books[bookCount].author);
        file >> books[bookCount].quantity;
        file.ignore();
        bookCount++;
    }

    file.close();
    cout << "Library data loaded successfully." << endl;
}

void addBook() {
    if (bookCount < 100) {
        cout << "Enter Book ID: ";
        cin >> books[bookCount].bookId;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, books[bookCount].title);

        cout << "Enter Author Name: ";
        getline(cin, books[bookCount].author);

        cout << "Enter Quantity: ";
        cin >> books[bookCount].quantity;
        cin.ignore();

        bookCount++;
        cout << "Book added successfully!" << endl;
    } else {
        cout << "Library is full. Cannot add more books." << endl;
    }
}

void searchBook() {
    string searchQuery;
    int choice;

    cout << "Search by: 1. Book ID  2. Title" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Enter Book ID to search: ";
        getline(cin, searchQuery);

        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookId == searchQuery) {
                cout << "Book ID: " << books[i].bookId << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "Quantity: " << books[i].quantity << endl;
                return;
            }
        }
        cout << "Book with ID " << searchQuery << " not found!" << endl;
    }
    else if (choice == 2) {
        cout << "Enter Title to search: ";
        getline(cin, searchQuery);

        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == searchQuery) {
                cout << "Book ID: " << books[i].bookId << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "Quantity: " << books[i].quantity << endl;
                return;
            }
        }
        cout << "Book with Title " << searchQuery << " not found!" << endl;
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void displayAllBooks() {
    if (bookCount == 0) {
        cout << "No books available in the library." << endl;
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        cout << "Book ID: " << books[i].bookId << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Quantity: " << books[i].quantity << endl;
        cout << "---------------------------" << endl;
    }
}

int main() {
    int choice;
    loadFromFile();

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add new book" << endl;
        cout << "2. Search for a book" << endl;
        cout << "3. Display all books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            displayAllBooks();
            break;
        case 4:
            saveToFile();
            cout << "Exiting the system." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
