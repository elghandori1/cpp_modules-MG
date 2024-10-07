/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:00:30 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/06 19:58:59 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

int main() {
    PhoneBook phoneBook;
    Contact contact;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof())
        {
            std::cout << "\nEnd of input detected " << std::endl;
            break;
        }else{
            std::cin.clear();
        }
        if (command == "ADD")
        {
            std::string input;
            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            contact.setFirstName(input);

            std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            contact.setLastName(input);

            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            contact.setNickname(input);

            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            contact.setPhoneNumber(input);

            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            contact.setDarkestSecret(input);
            
            phoneBook.addContact(contact);
        }
        else if (command == "SEARCH")
        {
            if (phoneBook.searchContacts() != 1) 
            {   
                int index;
                std::cout << "Enter index to display: ";
                std::cin >> index;
                if (std::cin.fail()) {
                    std::cout << "Please enter a valid integer." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    phoneBook.displayContact(index);
                }
            }
         }
         else if(command.empty()){
             std::cout << "empty input!" << std::endl;
        }
        else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}
