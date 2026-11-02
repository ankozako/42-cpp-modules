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

int	main(void)
{
	std::cout << "=== Test 1: Basic functionality ===" << std::endl;
	ClapTrap clap("Clapson");

	clap.attack("target dummy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n=== Test 2: Energy depletion ===" << std::endl;
	ClapTrap energyTest("Tired");
	for (int i = 0; i < 11; i++)
		energyTest.attack("dummy");
	
	std::cout << "\n=== Test 3: Death ===" << std::endl;
	ClapTrap mortal("Doomed");
	mortal.takeDamage(15);
	mortal.attack("ghost");
	mortal.beRepaired(5);

	std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
	ClapTrap original("Orig");
	ClapTrap copy(original);

	std::cout << "Destructors will be called" << std::endl;
	return (0);
}