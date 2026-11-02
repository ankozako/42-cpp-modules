/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:37:40 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/02 11:37:41 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "Creating heap zombie:" << std::endl;
	Zombie* heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete(heapZombie);

	std::cout << "\nCreating stack zombie:" << std::endl;
	randomChump("Stacker");
	std::cout << "\nEnd of main" << std::endl;
	return (0);
}
