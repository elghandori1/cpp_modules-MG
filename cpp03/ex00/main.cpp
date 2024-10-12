/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:31:57 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:31:58 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(4);

    /*
    //--------test 2:
        ClapTrap claptrap("CLTP");
        claptrap.attack("target1");
        claptrap.takeDamage(5);
        claptrap.beRepaired(21);
        claptrap.takeDamage(27);
        claptrap.beRepaired(21);
    */

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

        ClapTrap claptrap("CLTP-00");
        ClapTrap claptrap2("CLTP-01");
        claptrap2= claptrap;
        claptrap2.attack("enemy");
        claptrap2.takeDamage(6);
        claptrap2.takeDamage(2);
    */



    return 0;
}