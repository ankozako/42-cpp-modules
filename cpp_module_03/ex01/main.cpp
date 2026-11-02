/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:56:35 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/16 15:56:37 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "=== Test 1: Construction/Destruction ===" << std::endl;
	{
		ScavTrap scav("TomScavo");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: ScavTrap with real damage ===" << std::endl;
	ScavTrap fighter("Fighter");
	fighter.attack("enemy");
	fighter.takeDamage(30);
	fighter.beRepaired(20);
	fighter.guardGate();
	std::cout << std::endl;

	std::cout << "\n=== Test 3: Energy depletion ===" << std::endl;
	ScavTrap tired("Exhausted");
	for (int i = 0; i < 51; i++)
		tired.attack("dummy");
	std::cout << std::endl;

	std::cout << "\n=== Test 4: Compare ClapTrap and ScavTrap ===" << std::endl;
	ClapTrap clap("Clapson");
	ScavTrap scav1("TomScavo");
	clap.attack("target");
	scav1.attack("target");
	std::cout << std::endl;

	std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
	ScavTrap original("Orig");
	ScavTrap copy(original);
	original.attack("dummy");
	copy.attack("dummy");
	std::cout << std::endl;

	std::cout << "Destructors will be called" << std::endl;
	return (0);
}