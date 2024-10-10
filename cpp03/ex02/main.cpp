#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap frag("FRCT-03");
    frag.attack("enemy3");
    frag.takeDamage(15);
    frag.beRepaired(10);
    frag.highFivesGuys();
    return 0;
}
