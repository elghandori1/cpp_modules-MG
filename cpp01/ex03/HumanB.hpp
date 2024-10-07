/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:19:02 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/16 20:24:26 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(void);
        HumanB(std::string name);
        ~HumanB();
        void attack(void);
        void setWeapon(Weapon &weapon);
};
#endif