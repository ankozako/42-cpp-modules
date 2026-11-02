/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:08:38 by ankozako          #+#    #+#             */
/*   Updated: 2026/01/31 16:08:40 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
			phoneBook.searchContact();
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}
