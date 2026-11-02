/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:20:10 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/02 13:20:12 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
 
class Zombie
{
	private:
		std::string _name;

		public:
			Zombie();
			~Zombie();
			void	announce(void);
			void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif