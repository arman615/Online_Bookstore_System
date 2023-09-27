#include "Book.h"

Book::Book(const std::string &title, const std::string &author, const std::string &genre, double price, int quantity)
    : title(title), author(author), genre(genre), price(price), quantity(quantity) {}

const std::string &Book::getTitle() const {
    return title;
}

const std::string &Book::getAuthor() const {
    return author;
}

const std::string &Book::getGenre() const {
    return genre;
}

double Book::getPrice() const {
    return price;
}

int Book::getQuantity() const {
    return quantity;
}

void Book::setQuantity(int quantity) {
    this->quantity = quantity;
}
