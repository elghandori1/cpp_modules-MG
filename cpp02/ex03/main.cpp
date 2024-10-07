/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:23:17 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/05 21:23:19 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a(0,0);
    Point b(20,0);
    Point c(10,30);
    Point point(10,12);
    if (bsp(a, b, c, point))
        std::cout << "inside" << std::endl;
    else
        std::cout << "outside" << std::endl;
    return (0);
}
