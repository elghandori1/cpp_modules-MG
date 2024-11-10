/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Storage.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:19:51 by moel-gha          #+#    #+#             */
/*   Updated: 2024/11/07 19:19:52 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Storage.hpp"

Storage::Storage() : count(0) {
    for (int i = 0; i < 4; i++) {
        materias[i] = NULL;
    }
}

void Storage::add(AMateria* m) {
    if (count < 4 && m != NULL) {
        materias[count++] = m;
    }
}

Storage::~Storage() {
    for (int i = 0; i < count; i++) {
        delete materias[i];
    }
}
