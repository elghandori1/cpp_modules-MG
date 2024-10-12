/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:33:23 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:33:24 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Default")
{
	std::cout << "ScavTrap default constructor has been called!\n";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) 
{
    std::cout << "ScavTrap copy constructor has been called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap overloading assignment operator called" << std::endl;
    if (this != &other)
    {
    ClapTrap::operator=(other);
	this->name = other.name;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
    }
	return(*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " ~destroyed.\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ScavTrap " << this->name << " attacks " << target
        << ", causing " << this->attackDamage << " points of damage!\n";
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->name << " can't attack. Not enough energy or hit points!\n";
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode.\n";
}
