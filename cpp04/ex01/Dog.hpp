/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:08:43 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:08:44 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain* B;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        void makeSound(void) const;
};
#endif