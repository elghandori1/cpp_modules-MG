/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:08:38 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:08:39 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain* B;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);
        void makeSound(void) const;
};
#endif