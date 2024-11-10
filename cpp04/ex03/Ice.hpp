/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:04 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:29:05 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice &copy);
    Ice &operator=(const Ice &other);
    ~Ice();
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
