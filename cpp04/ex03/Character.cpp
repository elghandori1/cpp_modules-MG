/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:28:47 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/07 19:33:03 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default")
{
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(std::string name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &other) : name(other.name) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone(); 
        else
            inventory[i] = NULL;
    }
    std::cout <<"copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout <<"assignment operator called" << std::endl;
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
    std::cout << "NO place to add another Materia.\n";
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        unequippedStorage.add(inventory[idx]);
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {

    for (int i = 0; i < 4 ; i++)
	{
		if (idx == i && inventory[i] != NULL)
		{
			inventory[i]->use(target);
		}
	}
}
