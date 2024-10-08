#include "ClapTrap.hpp"

int main(){
   
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);


    /*
    //------copy constructor:

        ClapTrap claptrap("CLTP");
        ClapTrap claptrap2(claptrap);
        claptrap2.attack("enemy");
        claptrap2.takeDamage(6);
        claptrap2.takeDamage(2);
    */

    /*
    //------ overloading assignment:
  
        ClapTrap claptrap("CLTP");
        ClapTrap claptrap2 = claptrap;
        claptrap2.attack("enemy");
        claptrap2.takeDamage(6);
        claptrap2.takeDamage(2);
    */


    return 0;
}