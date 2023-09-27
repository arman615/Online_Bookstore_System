#ifndef Customer_H
#define Customer_H

#include <string>

class Customer {
private:
    std::string name;
    std::string contactInfo;

public:
    Customer(const std::string &name, const std::string &contactInfo);

    const std::string &getName() const;
    const std::string &getContactInfo() const;
};

#endif // Customer_H
