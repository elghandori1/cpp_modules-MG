#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created.\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destroyed.\n";
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
