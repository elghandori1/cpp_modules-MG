/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:33:04 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/12 16:33:05 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif 