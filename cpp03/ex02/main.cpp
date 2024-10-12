/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:33:06 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:33:07 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
