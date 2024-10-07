/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:52:25 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/09 13:47:19 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie = zombieHorde(2,"mohammed");

    int i =0;
    while(i <2){
        zombie[i].announce();
        i++;
    }
    delete[] zombie;
    return 0;
}
