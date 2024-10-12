/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:31:49 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:31:50 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor has been called!.\n";
    this->name = "default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap overloading assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " ~destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target 
        << ", causing " << this->attackDamage << " points of damage! \n";
        energyPoints--;
    } else {
        std::cout << "ClapTrap " <<  this->name << " can't attack. Not enough energy or hit points!\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0){
        hitPoints = 0;
    }
	if (hitPoints == 0)
		std::cout << this->name << " is dead." << std::endl;	
	else
		std::cout << this->name << " lost " << amount << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << this->name << " repairs itself for " << amount << " hit points. Current hit points: " 
        << this->hitPoints <<" current energyPoints: " << this->energyPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << this->name << " can't repair itself. Not enough energy or hit points!\n";
    }
}
