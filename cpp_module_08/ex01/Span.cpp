/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:38:14 by ankozako          #+#    #+#             */
/*   Updated: 2026/04/08 12:38:16 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
	_numbers.reserve(n);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::exception();
	_numbers.push_back(number);
}

int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::exception();
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int	diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::exception();
	std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());

	return *max - *min;
}

unsigned int	Span::size() const
{
	return _numbers.size();
}

unsigned int	Span::maxSize() const
{
	return _maxSize;
}