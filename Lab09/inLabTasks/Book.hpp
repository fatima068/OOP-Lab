#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string title, string author, string ISBN) : title(title), author(author), ISBN(ISBN) {}

    Book() : title(""), author(""), ISBN("0000000000000") {}
    
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getISBN() const {
        return ISBN;
    }

};

#endif