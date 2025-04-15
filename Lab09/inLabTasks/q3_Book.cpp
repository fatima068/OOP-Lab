#include <iostream>
#include "Book.hpp"
using namespace std;

class Library {
    private:
    Book* bookArr;
    int numOfBooks;

    public:
    Library() : bookArr(nullptr), numOfBooks(0) {}

    Library(Book* arr, int n) : bookArr(arr), numOfBooks(0) {}

    ~Library() {
        delete[] bookArr;
    }

    void addBook(Book b1) {
        Book* newArr = new Book[numOfBooks+1];
        for(int i = 0; i < numOfBooks; i++) {
            newArr[i] = bookArr[i];
        }
        newArr[numOfBooks] = b1;
        delete[] bookArr;
        bookArr = newArr;
        numOfBooks++;
    } 

    void removeBook(Book b1) {
        for (int i = 0; i < numOfBooks; i++) {
            if (bookArr[i].getISBN() == b1.getISBN()) {
                for (int j = i; j < numOfBooks - 1; j++) {
                    bookArr[j] = bookArr[j + 1];
                }
                numOfBooks--;
                break;
            }
        }
    }

    void searchBook(string title) {
        for (int i = 0; i < numOfBooks; i++) {
            if (bookArr[i].getTitle() == title) {
                cout << "book found: " << bookArr[i].getTitle() << " by " << bookArr[i].getAuthor() << " ISBN: " << bookArr[i].getISBN() << "" << endl;
                return;
            }
        }
        cout << "book not found: " << title << endl;
    }
};

int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    Book book2("To Kill a Mockingbird", "Harper Lee", "9780061120084");
    Book book3("1984", "George Orwell", "9780451524935");

    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.searchBook("To Kill a Mockingbird");
    library.removeBook(book2);
    library.searchBook("To Kill a Mockingbird");
    library.searchBook("The Great Gatsby");
    library.searchBook("1984");
}