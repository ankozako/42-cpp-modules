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

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "=== Test 1: DiamondTrap Construction/Destruction ===" << std::endl;
	{
		DiamondTrap diamond("Twinkle");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: DiamondTrap abilities ===" << std::endl;
	DiamondTrap diamond("Diamond");
	diamond.whoAmI();
	diamond.attack("target");
	diamond.takeDamage(50);
	diamond.beRepaired(30);
	diamond.guardGate();
	diamond.highFivesGuys();
	std::cout << std::endl;

	std::cout << "\n=== Test 3: Attribute verification ===" << std::endl;
	DiamondTrap test("Test");
	std::cout << "Testing attributes (shoud have: HP 100, Energy 50, Damage 30)" << std::endl;
	std::cout << "\nFirst attack (30 dmg):" << std::endl;
	test.attack("dummy");
	std::cout << "\nDepleting remaining energy (49 attacks):" << std::endl;
	for (int i = 0; i < 49; i++)
		test.attack("dummy");
	std::cout << "\nTrying one more attack (should fail):" << std::endl;
	test.attack("dummy");
	std::cout << "\nTrying to repair (should fail):" << std::endl;
	test.beRepaired(10);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 4: WhoamI ===" << std::endl;
	DiamondTrap d1("Annihilator");
	DiamondTrap d2("Destroyer");
	d1.whoAmI();
	d2.whoAmI();
	std::cout << std::endl;

	std::cout << "Destructors will be called" << std::endl;
	return (0);
}