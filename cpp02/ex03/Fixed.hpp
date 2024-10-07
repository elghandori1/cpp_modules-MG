/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:23:14 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/05 21:23:15 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int value;
        static const int  fractional_bits = 8;
    public:
        Fixed();
	    Fixed (const Fixed &fixed);
        Fixed (const int value);
        Fixed (const float value);
	    ~Fixed();
	    Fixed&	operator=(const Fixed &fixed);
	    int		getRawBits(void) const;
	    void	setRawBits( int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;
        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator-(void) const;
        Fixed operator/(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);
        static Fixed	&min(Fixed &fixed1, Fixed &fixed2);
		static Fixed	&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
};
std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);
#endif