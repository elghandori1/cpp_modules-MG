/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:09:23 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:09:24 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : B(new Brain()) {
    std::cout << "Dog created" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other), B(new Brain(*other.B)) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete B;
        B = new Brain(*other.B);
    }
    return *this;
}

Dog::~Dog() {
    delete B;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Haw ... " << std::endl;
}
