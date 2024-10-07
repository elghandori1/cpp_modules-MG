/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:22:41 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/05 21:22:42 by moel-gha         ###   ########.fr       */
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
	    void	setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);
#endif