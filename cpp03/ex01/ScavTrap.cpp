#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other){
    std::cout << "<ScavTrap copy constructor has been called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap overloading assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destructed.\n";
}

void ScavTrap::attack(const std::string &target) {
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode.\n";
}
