#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap {
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap(const std::string& name);
    ClapTrap();
    ClapTrap(const ClapTrap &Clap);
    ClapTrap& operator=(const ClapTrap &Clap);;
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
   
};

#endif 