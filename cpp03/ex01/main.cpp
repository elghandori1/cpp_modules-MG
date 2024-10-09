#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Scavvy");
    scav.attack("target");
    scav.takeDamage(2);
    scav.guardGate();
    return 0;
}
