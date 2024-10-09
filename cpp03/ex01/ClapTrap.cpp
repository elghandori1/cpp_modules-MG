#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target 
        << ", causing " << this->attackDamage << " points of damage!\n";
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
		std::cout << this->name << " lost " << amount << " damage points." << std::endl;
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
        std::cout << this->name << " can't repair itself. Not enough energy or hit points!\n";
    }
}
