/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:07:33 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:07:35 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog created" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}

Dog::Dog(std::string &type)
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = type;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog overloading assignment operator called\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog()
{ 
    std::cout << "Dog ~destroyed" << std::endl; 
}

void Dog::makeSound(void) const 
{ 
    std::cout << "Haw ... " << std::endl;
}