/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:19:55 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/02 13:19:56 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	hordeSize = 10;

	std::cout << "Creating a horde of " << hordeSize << " zombies" << std::endl;
	Zombie*	horde = zombieHorde(hordeSize, "Hordette");

	std::cout << "\nAnnouncing the horde:" << std::endl;
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	std::cout << "\nDeleting the horde:" << std::endl;
	delete[] horde;
	std::cout << "\nEnd of main" << std::endl;
	return (0);
}
