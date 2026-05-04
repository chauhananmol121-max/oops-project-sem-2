#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book() {
        id = 0;
        title = "";
        author = "";
        issued = false;
    }

    void setDetails(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    void display() {
        cout << "ID: " << id << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

class Library {
public:
    Book books[10];
    int count = 0;

    void addBook(int id, string title, string author) {
        books[count].setDetails(id, title, author);
        count++;
        cout << "Book added!\n";
    }

    void showBooks() {
        if (count == 0) { cout << "No books available.\n";
             return; 
         }
        for (int i = 0; i < count; i++)
            books[i].display();
    }

    void issueBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (books[i].issued) cout << "Already issued.\n";
                else { books[i].issued = true; cout << "Book issued!\n"; }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                books[i].issued = false;
                cout << "Book returned!\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    lib.addBook(1, "C++ Basics", "Bjarne");
    lib.addBook(2, "Clean Code", "Robert");

    int choice, id;
    string t, a;

    do {
        cout << "\n1. Show Books\n2. Add Book\n3. Issue Book\n4. Return Book\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            lib.showBooks();
        } else if (choice == 2) {
            cout << "ID: "; cin >> id;
            cout << "Title: "; cin >> t;
            cout << "Author: "; cin >> a;
            lib.addBook(id, t, a);
        } else if (choice == 3) {
            cout << "Enter Book ID: "; cin >> id;
            lib.issueBook(id);
        } else if (choice == 4) {
            cout << "Enter Book ID: "; cin >> id;
            lib.returnBook(id);
        }
    } while (choice != 0);

    return 0;
}