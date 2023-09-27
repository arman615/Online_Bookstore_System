#ifndef Book_H
#define Book_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    double price;
    int quantity;

public:
    Book(const std::string &title, const std::string &author, const std::string &genre, double price, int quantity);

    const std::string &getTitle() const;
    const std::string &getAuthor() const;
    const std::string &getGenre() const;
    double getPrice() const;
    int getQuantity() const;
    void setQuantity(int quantity);
};

#endif // Book_H
