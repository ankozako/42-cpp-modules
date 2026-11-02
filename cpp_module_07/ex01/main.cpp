/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:14:03 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/25 11:14:04 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T const& x)
{
	std::cout << x << " ";
}

void increment(int& x)
{
	x++;
}

void toUpper(std::string& str)
{
	if (!str.empty() && str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
}

int main()
{
	std::cout << "=== Test 1: Print integer array ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
	
	iter(intArray, intLen, print<int>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 2: Increment integers ===" << std::endl;
	std::cout << "Before: ";
	iter(intArray, intLen, print<int>);
	std::cout << std::endl;
	
	iter(intArray, intLen, increment);
	
	std::cout << "After:  ";
	iter(intArray, intLen, print<int>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 3: String array ===" << std::endl;
	std::string strArray[] = {"hello", "templates", "world"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
	
	std::cout << "Before: ";
	iter(strArray, strLen, print<std::string>);
	std::cout << std::endl;
	
	iter(strArray, strLen, toUpper);
	
	std::cout << "After:  ";
	iter(strArray, strLen, print<std::string>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 4: Double array ===" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);
	
	std::cout << "Values: ";
	iter(doubleArray, doubleLen, print<double>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 5: Const array (read-only) ===" << std::endl;
	const int constArray[] = {10, 20, 30, 40, 50};
	size_t constLen = sizeof(constArray) / sizeof(constArray[0]);
	
	std::cout << "Const:  ";
	iter(constArray, constLen, print<int>);
	std::cout << std::endl;
	
	return 0;
}
