/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:40:28 by ankozako          #+#    #+#             */
/*   Updated: 2026/04/08 12:40:30 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== Subject's Test ===" << std::endl;
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "\n=== Test 1: Exception when full ===" << std::endl;
	try
	{
		sp.addNumber(42);
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: Cannot add more numbers (full)" << std::endl;
	}
	
	std::cout << "\n=== Test 2: Exception with < 2 numbers ===" << std::endl;
	Span small(10);
	small.addNumber(5);
	
	try
	{
		std::cout << small.shortestSpan() << std::endl;
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: Not enough numbers for span" << std::endl;
	}
	
	std::cout << "\n=== Test 3: Empty span ===" << std::endl;
	Span empty(5);
	
	try
	{
		std::cout << empty.longestSpan() << std::endl;
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: Not enough numbers for span" << std::endl;
	}
	
	std::cout << "\n=== Test 4: Large span (10,000 numbers) ===" << std::endl;
	Span big(10000);
	
	std::srand(std::time(0));
	for (int i = 0; i < 10000; ++i)
		big.addNumber(std::rand());
	
	std::cout << "Added 10,000 random numbers" << std::endl;
	std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
	std::cout << "Longest span: " << big.longestSpan() << std::endl;
	
	std::cout << "\n=== Test 5: Using addRange (iterator range) ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	vec.push_back(400);
	vec.push_back(500);
	
	Span rangeSpan(10);
	rangeSpan.addRange(vec.begin(), vec.end());
	
	std::cout << "Added " << rangeSpan.size() << " numbers using addRange" << std::endl;
	std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
	
	std::cout << "\n=== Test 6: Negative numbers ===" << std::endl;
	Span negative(5);
	negative.addNumber(-10);
	negative.addNumber(-5);
	negative.addNumber(0);
	negative.addNumber(5);
	negative.addNumber(10);
	
	std::cout << "Shortest span: " << negative.shortestSpan() << std::endl;
	std::cout << "Longest span: " << negative.longestSpan() << std::endl;
	
	std::cout << "\n=== Test 7: All numbers identical ===" << std::endl;
	Span same(3);
	same.addNumber(42);
	same.addNumber(42);
	same.addNumber(42);
	
	std::cout << "Shortest span: " << same.shortestSpan() << std::endl;
	std::cout << "Longest span: " << same.longestSpan() << std::endl;
	
	std::cout << "\n=== Test 8: Two numbers only ===" << std::endl;
	Span two(2);
	two.addNumber(1);
	two.addNumber(100);
	
	std::cout << "Shortest span: " << two.shortestSpan() << std::endl;
	std::cout << "Longest span: " << two.longestSpan() << std::endl;
	
	return 0;
}