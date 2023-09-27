#include "BookStore.h"
#include <iostream>
#include <fstream>

void BookStore::registerBook(const std::string &title, const std::string &author, const std::string &genre, double price, int quantity) {
    Book book(title, author, genre, price, quantity);
    books.push_back(book);
    std::cout << "Book registered: " << title << std::endl;
}

void BookStore::registerCustomer(const std::string &name, const std::string &contactInfo) {
    Customer customer(name, contactInfo);
    customers.push_back(customer);
    std::cout << "Customer registered successfully: " << name << std::endl;
}

void BookStore::addToCart(const std::string &title) {
    Book *book = findBookByTitle(title);
    if (book != nullptr) {
        shoppingCart.push_back(*book);
        std::cout << "Book added to the Cart: " << title << std::endl;
    } else {
        std::cout << "Book not found: " << title << std::endl;
    }
}

void BookStore::removeFromCart(const std::string &title) {
    for (auto it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
        if (it->getTitle() == title) {
            shoppingCart.erase(it);
            std::cout << "Book removed from the cart: " << title << std::endl;
            return;
        }
    }
    std::cout << "Book not found in the cart: " << title << std::endl;
}

double BookStore::calculateTheCost() {
    double totalCost = 0;
    for (const Book &book : shoppingCart) {
        totalCost += book.getPrice();
    }
    return totalCost;
}

void BookStore::processPurchase() {
    for (const Book &book : shoppingCart) {
        Book *bookInStock = findBookByTitle(book.getTitle());
        if (bookInStock != nullptr && bookInStock->getQuantity() > 0) {
            bookInStock->setQuantity(bookInStock->getQuantity() - 1);
        }
    }
    shoppingCart.clear();
    std::cout << "Purchase processed successfully." << std::endl;
}

void BookStore::generatePurchaseHistoryReport() {
    std::ofstream file("purchase_history.txt");
    if (file.is_open()) {
        file << "Purchase History Report" << std::endl;
        file << "--------------------------------" << std::endl;
        for (const Book &book : shoppingCart) {
            file << "Title: " << book.getTitle() << std::endl;
            file << "Author: " << book.getAuthor() << std::endl;
            file << "Price: $" << book.getPrice() << std::endl;
            file << "----------------------------";
        }
        file << "Total cost: $" << calculateTheCost() << std::endl;
        file.close();
        std::cout << "Purchase history report generated successfully." << std::endl;
    } else {
        std::cout << "Failed to generate purchase history." << std::endl;
    }
}

void BookStore::printBooksInStock() {
    std::cout << "Books in Stock: " << std::endl;
    std::cout << "----------------------" << std::endl;
    for (const Book &book : books) {
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Genre: " << book.getGenre() << std::endl;
        std::cout << "Price: $" << book.getPrice() << std::endl;
        std::cout << "Quantity in Stock: " << book.getQuantity() << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

void BookStore::printCustomers() const {
    std::cout << "Registered Customers: " << std::endl;
    std::cout << "---------------------" << std::endl;
    for (const Customer &customer : customers) {
        std::cout << "Name: " << customer.getName() << std::endl;
        std::cout << "Contact Info: " << customer.getContactInfo() << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}

Book *BookStore::findBookByTitle(const std::string &title) {
    for (Book &book : books) {
        if (book.getTitle() == title) {
            return &book;
        }
    }
    return nullptr;
}
