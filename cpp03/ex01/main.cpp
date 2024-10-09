#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("CT-01");
    clap.attack("enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    ScavTrap scav("SCCT-02");
    scav.attack("enemy2");
    scav.takeDamage(2);
    scav.beRepaired(5);
    scav.guardGate();

    return 0;
}

