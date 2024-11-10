/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:16:39 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:16:40 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Default"){}
AMateria::AMateria(const AMateria &copy) : type(copy.type){}
AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria &copy)
{
    if (this != &copy)
        type = copy.type;
    return (*this);
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    (void) target;
}
