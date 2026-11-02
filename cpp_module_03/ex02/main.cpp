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
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "=== Test 1: FragTrap Construction/Destruction ===" << std::endl;
	{
		FragTrap frag1("Frageric");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: FragTrap abilities ===" << std::endl;
	FragTrap fighter("Destroyer");
	fighter.attack("enemy");
	fighter.takeDamage(40);
	fighter.beRepaired(25);
	fighter.highFivesGuys();
	std::cout << std::endl;

	std::cout << "\n=== Test 3: Compare all 3 types ===" << std::endl;
	ClapTrap clap("Clapson");
	ScavTrap scav("TomScavo");
	FragTrap frag("Frageric");

	std::cout << "\n--- Attacks ---" << std::endl;
	clap.attack("target");
	scav.attack("target");
	frag.attack("target");

	std::cout << "\n--- Special abilities ---" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	std::cout << std::endl;
	
	std::cout << "\n=== Test 4: Energy ===" << std::endl;
	FragTrap energetic("Energetic");
	std::cout << "FragTrap has 100 energy, attacking 101 times:" << std::endl;
	for (int i = 0; i < 101; i++)
	{
		energetic.attack("dummy");
	}
	std::cout << std::endl;

	std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
	FragTrap original("Orig");
	FragTrap copy(original);

	original.highFivesGuys();
	copy.highFivesGuys();
	std::cout << std::endl;

	std::cout << "Destructors will be called" << std::endl;
	return (0);
}