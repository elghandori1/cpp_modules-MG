/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:52:47 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/07 15:52:48 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name):name(name){}

Zombie::~Zombie()
{
	std::cout << this->name <<" is destroyed." <<std::endl;
}

void Zombie::announce()
{
	 std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

