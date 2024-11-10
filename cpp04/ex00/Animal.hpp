/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:07:25 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:07:26 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal 
{
protected:
    std::string type;
public:
    Animal();
    Animal(std::string &type);
    virtual ~Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal &other);
    virtual void makeSound() const ;
    std::string getType(void) const ;
};

#endif
