/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:06:10 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/06 12:06:12 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "===== SUBJECT TEST =====" << std::endl;
	{
		Fixed	a;
		Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << "===== COMPARISON OPERATORS =====" << std::endl;
	{
		Fixed	a(10.5f);
		Fixed	b(5.25f);
		Fixed	c(10.5f);

		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
		std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
		std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;
		std::cout << "a <= c: " << (a <= c ? "true" : "false") << std::endl;
		std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
		std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
	}

	std::cout << "===== ARITHMETIC OPERATORS =====" << std::endl;
	{
		Fixed	a(10);
		Fixed	b(3);

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "a + b = " << (a + b) << std::endl;
		std::cout << "a - b = " << (a - b) << std::endl;
		std::cout << "a * b = " << (a * b) << std::endl;
		std::cout << "a / b = " << (a / b) << std::endl;

		Fixed	c(65.65f);
		Fixed	d(2.5f);

		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "c + d = " << (c + d) << std::endl;
		std::cout << "c - d = " << (c - d) << std::endl;
		std::cout << "c * d = " << (c * d) << std::endl;
		std::cout << "c / d = " << (c / d) << std::endl;
	}

	std::cout << "===== INCREMENT/DECREMENT OPERATORS =====" << std::endl;
	{
		Fixed	a(5);

		std::cout << "Init a = " << a << std::endl;
		std::cout << "++a = " << ++a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a++ = " << a++ << std::endl;
		std::cout << "a = " << a << std::endl;

		std::cout << "\n Decrement" << std::endl;
		std::cout << "--a = " << --a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a-- = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
	}

	std::cout << "===== MIN/MAX FUNCTIONS =====" << std::endl;
	{
		Fixed	a(42.42f);
		Fixed	b(10.5f);

		std::cout << "a = " << a << " , b = " << b << std::endl;
		std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

		const Fixed	c(100.5f);
		const Fixed	d(100.75f);
		
		std::cout << "\nConst v: " << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
	}

	std::cout << "===== CHAINING OPERATORS =====" << std::endl;
	{
		Fixed	a(10);
		Fixed	b(5);
		Fixed	c(2);

		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "a + b + c = " << (a + b + c) << std::endl;
		std::cout << "a * b / c = " << (a * b / c) << std::endl;
		std::cout << "(a + b) * c =" << ((a + b) * c) << std::endl;
	}

	std::cout << "===== CONVERSION TEST =====" << std::endl;
	{
		Fixed	a(42);
		Fixed	b(42.42f);

		std::cout << "From int 42: " << a << std::endl;
		std::cout << "To int: " << a.toInt() << std::endl;
		std::cout << "To float: " << a.toFloat() << std::endl;
		std::cout << "\nFrom float 42.42: " << b << std::endl;
		std::cout << "To int: " << b.toInt() << std::endl;
		std::cout << "To float: " << b.toFloat() << std::endl;
	}
	return (0);
}
