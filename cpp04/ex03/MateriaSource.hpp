/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:24 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/06 16:29:25 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource& operator=(const MateriaSource &copy);
        ~MateriaSource();
        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};
#endif
