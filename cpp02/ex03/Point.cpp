/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:23:42 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/05 21:23:43 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float x, const float y): x(x), y(y){}
Point::Point(const Point &p):x(p.x), y(p.y){}
Point& Point::operator=(const Point &point)
{
    (void)point;
    return (*this);
}
Point::~Point(){}
const Fixed Point::get_x(void)
{
    return (this->x);
}

const Fixed Point::get_y(void)
{
    return (this->y);
}