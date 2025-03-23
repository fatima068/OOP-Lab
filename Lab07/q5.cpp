#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media() : title(""), publicationDate(""), uniqueID(""), publisher("") {}

    Media(string title, string publicationDate, string uniqueID, string publisher) : title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher) {}

    virtual void displayInfo() {
        cout << "Title: " << title << ", Publication Date: " << publicationDate << ", Unique ID: " << uniqueID << ", Publisher: " << publisher << endl;
    }

    void checkOut() {
        cout << "Checking out item: ";
        displayInfo();
    }

    string getId() { 
        return uniqueID; 
    }

    string getTitle() {
        return title;
    }

    string getPublisher() {
        return publisher;
    }

    string getPublicationDate() {
        return publicationDate;
    }

    void returnItem() {
        cout << "Returning item: ";
        displayInfo();
    }
};

class Book : public Media {
protected:
    string isbn, author;
    int numPages;

public:
    Book() : isbn(""), numPages(0), author(""), Media() {}

    Book(string title, string publicationDate, string uniqueID, string publisher, string isbn, string author, int numPages) : isbn(isbn), author(author),numPages(numPages), Media(title, publicationDate, uniqueID, publisher) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "ISBN: " << isbn << ", Number of Pages: " << numPages << endl;
    }
};

class DVD : public Media {
protected:
    string director;
    int duration;
    int rating;

public:
    DVD() : director(""), duration(0), rating(0), Media() {}

    DVD(string title, string publicationDate, string uniqueID, string publisher, string director, int duration, int rating) : director(director), duration(duration), rating(rating), Media(title, publicationDate, uniqueID, publisher) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << ", Duration: " << duration << ", Rating: " << rating << endl;
    }
};

class CD : public Media {
protected:
    string artist;
    int numOfTracks;
    string genre;

public:
    CD() : artist(""), numOfTracks(0), genre(""), Media() {}

    CD(string title, string publicationDate, string uniqueID, string publisher, string artist, int numOfTracks, string genre) : artist(artist), numOfTracks(numOfTracks), genre(genre), Media(title, publicationDate, uniqueID, publisher) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << ", Number of Tracks: " << numOfTracks << ", Genre: " << genre << endl;
    }
};

class Magazine : public Media {
    string genre;
    int numberOfPages;

public:
    Magazine() : Media(), genre(""), numberOfPages(0) {}
    
    Magazine(string title, string publicationDate, string uniqueID, string publisher, string genre, int numberOfPages) : Media(title, publicationDate, uniqueID, publisher), genre(genre), numberOfPages(numberOfPages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Genre: " << genre << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};

class System {
    Media** media;
    int numMedia;

public:
    System() : media(nullptr), numMedia(0) {}

    void addNewMedia(Media* mobj) {
        Media** newMedia = new Media*[numMedia + 1];    
        for (int i = 0; i < numMedia; i++) {
            newMedia[i] = media[i];
        }
        newMedia[numMedia] = mobj;
        delete[] media;
        media = newMedia;
        numMedia++;
    }

    bool searchMedia(string id) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id) {
                return true;
            }
        }
        return false;
    }

    bool searchMedia(string id, string title) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id && media[i]->getTitle() == title) {
                return true;
            }
        }
        return false;
    }

    bool searchMedia(string id, string title, string publisher) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id && media[i]->getTitle() == title && media[i]->getPublisher() == publisher) {
                return true;
            }
        }
        return false;
    }

    bool searchMedia(string id, string title, string publisher, string date) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id && media[i]->getTitle() == title && media[i]->getPublisher() == publisher && media[i]->getPublicationDate() == date) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    System mediaSystem;
    Book novel("Lightining Thief", "2005", "B1", "Book People", "9780451524935", "chbosky", 328);
    DVD movie("Perks Of Being A Wallflower", "2007", "D1", "Warner Bros", "Stephen Chbosky", 136, 8);
    CD album("Nevermind", "1992", "C1", "Records", "Nirvana", 10, "Grunge");
    Magazine journal("Time", "2023", "M1", "Time USA", "News", 50);
    mediaSystem.addNewMedia(&novel);
    mediaSystem.addNewMedia(&movie);
    mediaSystem.addNewMedia(&album);
    mediaSystem.addNewMedia(&journal);

    cout << "Searching for media using ID: ";
    if (mediaSystem.searchMedia("B1")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for media using ID and title: ";
    if (mediaSystem.searchMedia("D1", "Perks Of Being A Wallflower")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for media using ID, title, and publisher: ";
    if (mediaSystem.searchMedia("C1", "Nevermind", "Records")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for media using ID, title, publisher, and date: ";
    if (mediaSystem.searchMedia("M1", "Time", "Time USA", "2023")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << endl;
    novel.checkOut();
    movie.returnItem();
}