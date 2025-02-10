#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int ID;
    string title;
    string author;
    bool availability;

public:
    Book() {
        ID = 0;
        title = ""; 
        author = "";
        availability = false; 
    }

    Book(int ID, string title, string author, bool availability) {
        this->ID = ID;
        this->title = title;
        this->author = author;
        this->availability = availability;
    }

    Book(int ID, string title, string author) {
        this->ID = ID;
        this->title = title;
        this->author = author;
        this->availability = true; 
    }

    int getId() {
        return ID;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    bool isAvailable() {
        return availability;
    }

    void setId(int ID) {
        this->ID = ID;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setAuthor(string author) {
        this->author = author;
    }

    void setAvailability(bool availability) {
        this->availability = availability;
    }
};

class Library {
private:
    Book* books;
    int numOfBooks; 

public:
    Library() {
        books = nullptr;
        numOfBooks = 0;
    }

    Library(Book* arr, int numOfBooks) {
        this->numOfBooks = numOfBooks;
        books = new Book[numOfBooks];
        for (int i = 0; i < numOfBooks; i++) {
            books[i] = arr[i];
        }
    }

    void addBook(int id) {
        string t, a;
        bool availability;

        Book* newBooks = new Book[numOfBooks + 1];
        for (int i = 0; i < numOfBooks; i++) {
            newBooks[i] = books[i]; 
        }

        cout << "Enter Book title: ";
        getline(cin, t);
        cout << "Enter Book author: ";
        getline(cin, a);
        cout << "Enter Book availability (1 for available, 0 for unavailable): ";
        cin >> availability;

        newBooks[numOfBooks].setId(id);
        newBooks[numOfBooks].setTitle(t);
        newBooks[numOfBooks].setAuthor(a);
        newBooks[numOfBooks].setAvailability(availability);

        delete[] books; 
        books = newBooks;
        numOfBooks++;
        cout << "Book successfully added" << endl;
    }

    void borrowBook(int id) {
        for (int i = 0; i < numOfBooks; i++) {
            if (books[i].getId() == id) {
                if (books[i].isAvailable()) {
                    books[i].setAvailability(false);
                    cout << books[i].getTitle() << ": borrowed successfully" << endl;
                    return;
                }
                cout << books[i].getTitle() << ": already borrowed" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < numOfBooks; i++) {
            if (books[i].getId() == id) {
                if (!books[i].isAvailable()) {
                    books[i].setAvailability(true);
                    cout << books[i].getTitle() << ": returned successfully" << endl;
                    return;
                }
                cout << books[i].getTitle() << ": already available" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void displayAll() {
        cout << "All Available books: " << endl;
        cout << "ID \t Title \t Author" << endl;
        for (int i = 0; i < numOfBooks; i++) {
            if (books[i].isAvailable()) {
                cout << books[i].getId() << "\t" << books[i].getTitle() << "\t" << books[i].getAuthor() << endl;
            }
        }
    }
};

int main() {
    Book b1(1, "harry potter", "jk rowling");
    Book b2(2, "percy jackson", "rick riordan");
    Book b3(3, "walllower", "stephen chbosky");

    Book books[] = {b1, b2, b3};

    Library library(books, 3); 

    library.displayAll();

    library.borrowBook(1);
    library.borrowBook(3);
    cout << "\nAvailable books after borrowing: " << endl;
    library.displayAll();

    library.returnBook(1);
    cout << "\nAvailable books after returning: " << endl;
    library.displayAll();

    library.addBook(4);

    cout << "\nAll books in the library" << endl;
    library.displayAll();
}