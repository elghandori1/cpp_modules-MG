/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Storage.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:19:58 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/07 19:19:59 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "AMateria.hpp"

class Storage {
private:
    AMateria* materias[4];
    int count;

public:
    Storage();
    void add(AMateria* m);
    ~Storage();
};

#endif
