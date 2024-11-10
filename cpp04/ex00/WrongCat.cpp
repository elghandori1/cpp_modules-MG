/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:07:57 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:07:58 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat created" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(std::string &type)
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = type;
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = other.type;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat ~destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat overloading assignment operator called\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat Meow ..." << std::endl;
}
