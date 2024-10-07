/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:23:44 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/05 21:23:45 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &p);
        Point& operator=(const Point &point);
        ~Point(void);
        const Fixed get_x(void);
        const Fixed get_y(void);
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
float triangleArea(Point a, Point b, Point c);
#endif