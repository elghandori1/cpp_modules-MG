#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(4);

    return 0;
}