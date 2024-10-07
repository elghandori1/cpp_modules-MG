#include "PhoneBook.hpp"

void PhoneBook::addContact(const Contact &contact)
{
    if (contactCount < 8)
    {
        contacts[contactCount] = contact;
        contactCount++;
    } else {
        int i = 1;
        while (i < 8) {
            contacts[i - 1] = contacts[i];
            i++;
        }
        contacts[7] = contact;
    }
}

int PhoneBook::searchContacts() const 
{
    if(contactCount != 0){
         std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;

    int i = 0;
    while (i < contactCount) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << contacts[i].getFirstName().substr(0, 9) + "." << "|"
                  << std::setw(10) << contacts[i].getLastName().substr(0, 9) + "." << "|"
                  << std::setw(10) << contacts[i].getNickname().substr(0, 9) + "." << std::endl;
        i++;
    }
    return 0;
    }else
    {
        std::cout<< std::setw(10) <<" empty data !" <<std::endl;
        return 1;
    }
   
}

void PhoneBook::displayContact(int index) const {
    if (index >= 0 && index < contactCount) {
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}
