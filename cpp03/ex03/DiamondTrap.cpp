/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:33:47 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:33:48 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), name("Default") {
    this->hitPoints =  FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " created with default values.\n";
}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    this->hitPoints =  FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " created.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy.ClapTrap::name), FragTrap(copy), ScavTrap(copy), name(copy.name)
{
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    std::cout << "DiamondTrap " << this->name << " copied.\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
    if (this != &copy) {
        ClapTrap::operator=(copy);
        FragTrap::operator=(copy);
        ScavTrap::operator=(copy);
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    std::cout << "DiamondTrap " << this->name << " assigned.\n";
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " ~destroyed.\n";
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << ".\n";
}
