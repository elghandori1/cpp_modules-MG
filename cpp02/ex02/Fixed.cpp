/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:22:56 by moel-gha          #+#    #+#             */
/*   Updated: 2024/10/05 21:38:39 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0){}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed(){}

Fixed::Fixed(const int value)
{
    this->value = value << this->fractional_bits;
}
Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << this->fractional_bits));
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->value = fixed.value;
    return (*this);
}

int Fixed::getRawBits() const
{
    return (this->value);
}

void Fixed::setRawBits( int const raw)
{
    this->value = raw;
}

int Fixed::toInt() const
{
    return (this->value >> this->fractional_bits);
}

float Fixed::toFloat() const
{
    return ((float)this->value / (1 << this->fractional_bits));
}

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->value > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->value >= fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->value < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->value <= fixed.getRawBits());
}
bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->value == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->value != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed f;
    f.setRawBits(this->value + fixed.getRawBits());
    return (f);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed f;
    f.setRawBits(this->value - fixed.getRawBits());
    return (f);
}

Fixed Fixed::operator-(void) const
{
    Fixed f;
    f.setRawBits((this->value) * -1);
    return (f);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed f;
    f.setRawBits((this->value * fixed.getRawBits()) >> 8);
    return (f);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed f;
    f.setRawBits((this->value / fixed.getRawBits()) << 8);
    return (f);
}

Fixed Fixed::operator++(void)
{
    (this->value)++;
    return (*this);
}

Fixed Fixed::operator--(void)
{
    (this->value)--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    (this->value)++;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    (this->value)--;
    return (tmp);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}
