/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:11:07 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/25 11:11:09 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{

	Data original;
	original.name = "Test Data";
	original.value = 42;
	original.price = 19.99;
	
	std::cout << "=== Original Data ===" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "Name: " << original.name << std::endl;
	std::cout << "Value: " << original.value << std::endl;
	std::cout << "Price: " << original.price << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&original);
	std::cout << "\n=== Serialized ===" << std::endl;
	std::cout << "Integer representation: " << serialized << std::endl;
	std::cout << "In hexadecimal: 0x" << std::hex << serialized << std::dec << std::endl;
	
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "\n=== Deserialized Data ===" << std::endl;
	std::cout << "Address: " << deserialized << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Value: " << deserialized->value << std::endl;
	std::cout << "Price: " << deserialized->price << std::endl;
	
	std::cout << "\n=== Verification ===" << std::endl;
	if (&original == deserialized)
		std::cout << "Success! Pointers are equal." << std::endl;
	else
		std::cout << "Error! Pointers are different." << std::endl;
	
	if (original.name == deserialized->name &&
		original.value == deserialized->value &&
		original.price == deserialized->price)
		std::cout << "Success! Data is identical." << std::endl;
	else
		std::cout << "Error! Data is different." << std::endl;
	
	return 0;
}
