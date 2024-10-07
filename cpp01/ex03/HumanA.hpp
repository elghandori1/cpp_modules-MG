/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:18:56 by moel-gha          #+#    #+#             */
/*   Updated: 2024/09/10 21:28:11 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
class HumanA
{
    private:
        std::string name;
        Weapon &weapon;
    public:
        HumanA(std::string name ,Weapon &weapon);
        ~HumanA();
        void attack(void);
};

#endif