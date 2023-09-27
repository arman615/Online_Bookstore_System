#include "Customer.h"

Customer::Customer(const std::string &name, const std::string &contactInfo)
    : name(name), contactInfo(contactInfo) {}

const std::string &Customer::getName() const {
    return name;
}

const std::string &Customer::getContactInfo() const {
    return contactInfo;
}
