/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:07:25 by ankozako          #+#    #+#             */
/*   Updated: 2026/01/31 12:07:27 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0) , _id(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::_truncate(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::_displayContact(int index) const
{
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::_displayList() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getNickname()) << std::endl;
	}
}

bool	PhoneBook::_isValidPhone(std::string phone) const
{
	if (phone.empty())
		return (false);
	for (size_t i = 0; i < phone.length(); i++)
	{
		if (!std::isdigit(phone[i]))
			return (false);
	}
	return (true);
}

void	PhoneBook::addContact()
{
	std::string	fields[5];
	std::string prompts[5] =
	{
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Darkest secret: "
	};

	std::cout << "*****************************" << std::endl;
	std::cout << "*      ADD NEW CONTACT      *" << std::endl;
	std::cout << "*****************************" << std::endl << std::endl;

	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << prompts[i];
			std::getline(std::cin, fields[i]);

			if (fields[i].empty())
			{
				std::cout << "Field cannot be empty. Please try again." << std::endl;
				continue ;
			}
			if (i == 3 && !_isValidPhone(fields[i]))
			{
				std::cout << "Phone number must contain only digits. Please try again." << std::endl;
				continue ;
			}
			break ;
		}
	}
	_contacts[_id % 8].setFirstName(fields[0]);
	_contacts[_id % 8].setLastName(fields[1]);
	_contacts[_id % 8].setNickname(fields[2]);
	_contacts[_id % 8].setPhoneNumber(fields[3]);
	_contacts[_id % 8].setDarkestSecret(fields[4]);
	if (_count < 8)
		_count++;
	int	current_pos = (_id % 8) + 1;
	if (_id >= 8)
		std::cout << "Contact added at position " << current_pos << "(oldest overwritten)." << std::endl;
	else
		std::cout << "Contact added at position " << current_pos << std::endl;
	_id++;
}

void	PhoneBook::searchContact()
{
	if (_count == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	_displayList();
	std::cout << "Enter index: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
	{
		int	index = input[0] - '1';
		if (index < _count)
			_displayContact(index);
		else
			std::cout << "Invalid index!" << std::endl;
	}
	else
		std::cout << "Invalid input!" << std::endl;
}
