/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:07:28 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:07:29 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat created" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    type = other.type;
}

Cat::Cat(std::string &type)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = type;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat overloading assignment operator called\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat ~destroyed" << std::endl;
}

void Cat::makeSound(void) const 
{
    std::cout << "Meow ..." << std::endl;
}