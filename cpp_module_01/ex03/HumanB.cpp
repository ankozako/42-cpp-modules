/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:13:12 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/04 10:13:13 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (_weapon)
	{
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << _name << " has no weapon!" << std::endl;
	}
}
