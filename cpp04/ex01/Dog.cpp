/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:08:41 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:08:42 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): B(new Brain())
{
    std::cout << "Dog created" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other), B(new Brain(*other.B)) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other) {
        Animal::operator=(other);
        delete B;
        B = new Brain(*other.B);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{ 
    std::cout << "Dog ~destroyed" << std::endl;
    delete B;
}

void Dog::makeSound(void) const 
{ 
    std::cout << "Haw ... " << std::endl;
}