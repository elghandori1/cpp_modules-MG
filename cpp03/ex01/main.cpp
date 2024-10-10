#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("SCCT-02");
    scav.attack("enemy2");
    scav.takeDamage(2);
    scav.beRepaired(5);
    scav.guardGate();

    return 0;
}

