/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:06:18 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/06 12:06:19 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(const int intValue)
{
	this->_value = intValue << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	this->_value = roundf(floatValue * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_fractionalBits);
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}
bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);	
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits((this->_value * other._value) >> this->_fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits((this->_value << this->_fractionalBits) / other._value) ;
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->_value++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->_value--;
	return (temp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}