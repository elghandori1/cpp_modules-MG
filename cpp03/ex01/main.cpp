/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:32:35 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:32:36 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

