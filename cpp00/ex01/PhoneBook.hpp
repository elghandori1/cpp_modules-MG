#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {

private:
    Contact contacts[8];
    int contactCount;
public:
    PhoneBook() : contactCount(0) {}
    void addContact(const Contact &contact);
    int searchContacts() const;
    void displayContact(int index) const;
};

#endif
