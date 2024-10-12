/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:33:57 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:33:58 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("DMCT-04");
    diamond.attack("target");
    diamond.takeDamage(40);
    diamond.beRepaired(14);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();

    return 0;
}
