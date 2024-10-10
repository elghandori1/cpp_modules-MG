#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default"){
    std::cout << "FragTrap default constructor has been called!\n";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created.\n";
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) 
{
    std::cout << "FragTrap copy constructor has been called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap overloading assignment operator called" << std::endl;
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

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " ~destroyed.\n";
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->name << " requests high fives!" << std::endl;
}