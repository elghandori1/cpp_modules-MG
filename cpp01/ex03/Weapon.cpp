/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:18:43 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/16 20:20:18 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type):type(type){}

Weapon::~Weapon(){}

const std::string &Weapon::getType(void){
    return this->type;
}

void Weapon::setType(const std::string &type){
    this->type = type;
}
