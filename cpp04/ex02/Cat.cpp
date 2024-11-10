/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:09:18 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:09:19 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : B(new Brain()) {
    std::cout << "Cat created" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other), B(new Brain(*other.B)) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
}

Cat& Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete B;
        B = new Brain(*other.B);
    }
    return *this;
}

Cat::~Cat() {
    delete B;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow ..." << std::endl;
}
