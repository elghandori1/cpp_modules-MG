/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:23:10 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/05 21:23:11 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float triangleArea(Point a, Point b, Point c)
{
    Fixed Area((a.get_x() * (b.get_y() - c.get_y())) + (b.get_x() * (c.get_y() - a.get_y())) + (c.get_x() * (a.get_y() - b.get_y())));
    return (fabs(Area.toFloat() / 2.0));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float Area = triangleArea(a, b, c);
    float Area1 = triangleArea(point, b, c);
    float Area2 = triangleArea(a, point, c);
    float Area3 = triangleArea(a, b, point);
    return (Area == (Area1 + Area2 + Area3));
}