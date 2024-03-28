#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
class Book {
public:
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }

private:
    std::string title;
    std::string author;
    std::string isbn;
};

class LibraryManagementSystem {
public:
    void addBook(const std::string& title, const std::string& author, const std::string& isbn);
    void removeBook(const std::string& title);
    std::vector<Book> findBooksByTitle(const std::string& title) const;
    std::vector<Book> findBooksByAuthor(const std::string& author) const;

private:
    std::vector<Book> books;
};

void LibraryManagementSystem::addBook(const std::string& title, const std::string& author, const std::string& isbn) {
    books.emplace_back(title, author, isbn);
}

void LibraryManagementSystem::removeBook(const std::string& title) {
    books.erase(std::remove_if(books.begin(), books.end(),
        [&title](const Book& book) { return book.getTitle() == title; }),
        books.end());
}

std::vector<Book> LibraryManagementSystem::findBooksByTitle(const std::string& title) const {
    std::vector<Book> foundBooks;
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

std::vector<Book> LibraryManagementSystem::findBooksByAuthor(const std::string& author) const {
    std::vector<Book> foundBooks;
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

int main() {
    LibraryManagementSystem library;

    library.addBook("Gevorg Marzpetuni", "Muracan", "1234567890");
    library.addBook("The Old Man and the Sea", "Ernest Hemingway", "0987654321");

    // Find books by title and print their details
    std::vector<Book> booksByTitle = library.findBooksByTitle("Gevorg Marzpetuni");
    std::cout << "Books with title 'Gevorg Marzpetuni':" << std::endl;
    for (const auto& book : booksByTitle) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    // Find books by author and print their details
    std::vector<Book> booksByAuthor = library.findBooksByAuthor("Ernest Hemingway");
    std::cout << "\nBooks by author 'Ernest Hemingway':" << std::endl;
    for (const auto& book : booksByAuthor) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    return 0;
}


