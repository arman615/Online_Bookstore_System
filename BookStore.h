#ifndef BookStore_H
#define BookStore_H

#include <vector>
#include "book.h"
#include "customer.h"

class BookStore {
private:
    std::vector<Book> books;
    std::vector<Customer> customers;
    std::vector<Book> shoppingCart;

public:
    void registerBook(const std::string &title, const std::string &author, const std::string &genre, double price, int quantity);
    void registerCustomer(const std::string &name, const std::string &contactInfo);
    void addToCart(const std::string &title);
    void removeFromCart(const std::string &title);
    double calculateTheCost();
    void processPurchase();
    void generatePurchaseHistoryReport();
    void printBooksInStock();
    void printCustomers() const;

private:
    Book *findBookByTitle(const std::string &title);
};

#endif // BookStore_H
