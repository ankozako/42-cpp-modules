/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:13:19 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/04 10:13:21 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class	HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;
	
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack() const;
};

#endif
