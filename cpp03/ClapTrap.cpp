#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "<ClapTrap constructor has been called" << std::endl;
	*this = other; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap &Clap)
{
    std::cout << "ClapTrap overloading assignment operator called" << std::endl;
    if (this != &Clap)
    {
        this->name = Clap.name;
        this->hitPoints = Clap.hitPoints;
        this->energyPoints = Clap.energyPoints;
        this->attackDamage = Clap.attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target) 
{
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target 
        << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " <<  this->name << " can't attack. Not enough energy or hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0){
        hitPoints = 0;
    }
	if (hitPoints == 0)
		std::cout << "ClapTrap " << this->name << " is dead." << std::endl;	
	else
		std::cout << name << " lost " << amount << " damage points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points. Current hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't repair itself. Not enough energy or hit points!" << std::endl;
    }
}
