/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:09:06 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:09:07 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{ 
    std::cout << "Animal created" << std::endl; 
}

Animal::Animal(std::string &name) : type(name)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal overloading assignment operator called\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{ 
    std::cout << "Animal ~destroyed" << std::endl; 
}

std::string Animal::getType(void) const
{
    return (this->type);
}
