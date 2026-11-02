/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:14:25 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/25 11:14:27 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << "=== Test 1: Default constructor (empty array) ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
 
	std::cout << "\n=== Test 2: Parametric constructor ===" << std::endl;
	Array<int> numbers(5);
	std::cout << "Array size: " << numbers.size() << std::endl;
	
	std::cout << "Initial values: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
 
	std::cout << "\n=== Test 3: Modifying elements ===" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;
	
	std::cout << "Modified values: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
 
	std::cout << "\n=== Test 4: Copy constructor (deep copy) ===" << std::endl;
	Array<int> copy(numbers);
	std::cout << "Copy size: " << copy.size() << std::endl;
	std::cout << "Copy values: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;
 
	std::cout << "\nModifying copy..." << std::endl;
	copy[0] = 999;
	
	std::cout << "Original[0]: " << numbers[0] << std::endl;
	std::cout << "Copy[0]:     " << copy[0] << std::endl;
 
	std::cout << "\n=== Test 5: Assignment operator ===" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	
	std::cout << "Assigned size: " << assigned.size() << std::endl;
	std::cout << "Assigned values: ";
	for (unsigned int i = 0; i < assigned.size(); i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl;
 
	std::cout << "\nModifying assigned..." << std::endl;
	assigned[1] = 777;
	
	std::cout << "Original[1]: " << numbers[1] << std::endl;
	std::cout << "Assigned[1]: " << assigned[1] << std::endl;
 
	std::cout << "\n=== Test 6: Out of bounds access ===" << std::endl;
	try
	{
		std::cout << "Accessing index 10 (out of bounds)..." << std::endl;
		std::cout << numbers[10] << std::endl;
		std::cout << "✗ ERROR: Should have thrown exception!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "✓ Exception caught correctly" << std::endl;
	}
 
	std::cout << "\n=== Test 7: Empty array access ===" << std::endl;
	try
	{
		std::cout << "Accessing index 0 of empty array..." << std::endl;
		std::cout << empty[0] << std::endl;
		std::cout << "✗ ERROR: Should have thrown exception!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "✓ Exception caught correctly" << std::endl;
	}
 
	std::cout << "\n=== Test 8: String array ===" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	
	std::cout << "Strings: ";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << " ";
	std::cout << std::endl;
 
	return 0;
}