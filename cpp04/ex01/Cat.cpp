/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:08:36 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:08:37 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():B(new Brain())
{
    std::cout << "Cat created" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other),B(new Brain(*other.B))
{
    std::cout << "Cat copy constructor called" << std::endl;
    type = other.type;
}

Cat& Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete B;
        B = new Brain(*other.B);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat ~destroyed" << std::endl;
    delete B;
}

void Cat::makeSound(void) const 
{
    std::cout << "Meow ..." << std::endl;
}
