/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:08:04 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 19:04:47 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORONGCAT_HPP
# define WORONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(std::string &type);
        WrongCat(const WrongCat &other);
        WrongCat& operator=(const WrongCat &other);
        void makeSound() const;
};
#endif