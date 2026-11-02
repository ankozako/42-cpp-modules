/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:17:29 by ankozako          #+#    #+#             */
/*   Updated: 2026/04/08 12:17:31 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "=== Test 1: std::vector<int> ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 2: Element not found (vector) ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 3: std::list<int> ===" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	
	try
	{
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 4: Element not found (list) ===" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(lst, 99);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 5: std::deque<int> ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);
	
	try
	{
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 6: First element ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 1);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 7: Last element ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 8: Empty container ===" << std::endl;
	std::vector<int> empty;
	try
	{
		std::vector<int>::iterator it = easyfind(empty, 1);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 9: Duplicate values (finds first) ===" << std::endl;
	std::vector<int> duplicates;
	duplicates.push_back(5);
	duplicates.push_back(10);
	duplicates.push_back(5);
	duplicates.push_back(15);
	
	try
	{
		std::vector<int>::iterator it = easyfind(duplicates, 5);
		std::cout << "Found at position: " << (it - duplicates.begin()) << std::endl;
		std::cout << "Value: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}