/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:52:36 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/07 15:52:37 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{   
    Zombie* myZombie = newZombie("mohammed");
    myZombie->announce();
    delete myZombie;

    randomChump("elghandori");
    return 0;
}
