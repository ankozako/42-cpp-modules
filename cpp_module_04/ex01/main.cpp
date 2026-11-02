/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:55:49 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/27 12:55:51 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "===Subject test===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n=== Array of Animals (half Dog, half Cat) ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];
	
	for (int idx = 0; idx < arraySize / 2; idx++)
		animals[idx] = new Dog();
	
	for (int idx = arraySize / 2; idx < arraySize; idx++)
		animals[idx] = new Cat();
	
	std::cout << "\n=== Deleting animals ===" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
		delete animals[idx];
	
	std::cout << "\n=== Testing Brain with Ideas ===" << std::endl;
	Dog dog;
	dog.getBrain()->setIdea(0, "I love bones");
	dog.getBrain()->setIdea(1, "Cats are friends");
	dog.getBrain()->setIdea(2, "Squirrel!");
	
	std::cout << "Dog's ideas:\n";
	std::cout << "  " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "  " << dog.getBrain()->getIdea(1) << std::endl;
	std::cout << "  " << dog.getBrain()->getIdea(2) << std::endl;
	
	std::cout << "\n=== Testing Deep Copy ===" << std::endl;
	Dog basic;
	basic.getBrain()->setIdea(0, "Original idea");
	
	{
		Dog tmp = basic;
		std::cout << "Basic brain address: " << basic.getBrain() << std::endl;
		std::cout << "Tmp brain address:   " << tmp.getBrain() << std::endl;
		std::cout << "Tmp idea: " << tmp.getBrain()->getIdea(0) << std::endl;
		
		tmp.getBrain()->setIdea(0, "Modified idea");
		std::cout << "\nAfter modifying tmp:\n";
		std::cout << "Basic idea: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "Tmp idea:   " << tmp.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "Tmp destroyed, basic still exists\n";

	return 0;
}