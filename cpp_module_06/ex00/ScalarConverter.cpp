/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:10:37 by ankozako          #+#    #+#             */
/*   Updated: 2026/03/25 11:10:39 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static bool isChar(std::string const &input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	return false;
}

static bool isSpecialFloat(std::string const &input)
{
	return (input == "-inff" || input == "+inff" || input == "nanf");
}

static bool isSpecialDouble(std::string const &input)
{
	return (input == "-inf" || input == "+inf" || input == "nan");
}

static bool isFloat(std::string const &input)
{
	if (input.length() < 2 || input[input.length() - 1] != 'f')
		return false;
	std::string withoutF = input.substr(0, input.length() - 1);
	if (withoutF.find('.') == std::string::npos)
		return false;
	char *endptr;
	strtod(withoutF.c_str(), &endptr);
	return (*endptr == '\0');
}

static bool isInt(std::string const &input)
{
	if (input.find('.') != std::string::npos)
		return false;
	char *endptr;
	strtol(input.c_str(), &endptr, 10);
	return (*endptr == '\0');
}

static bool isDouble(std::string const &input)
{
	if (input.find('.') == std::string::npos)
		return false;
	char *endptr;
	strtod(input.c_str(), &endptr);
	return (*endptr == '\0');
}

static int detectType(std::string const &input)
{
	if (input.length() == 0)
		return -1;
	if (isChar(input))
		return 0;
	if (isSpecialFloat(input))
		return 2;
	if (isSpecialDouble(input))
		return 3;
	if (isFloat(input))
		return 2;
	if (isInt(input))
		return 1;
	if (isDouble(input))
		return 3;
	return -1;
}

static void printChar(double value, bool impossible)
{
	std::cout << "char: ";
	if (impossible || std::isnan(value) || std::isinf(value))
		std::cout << "impossible";
	else if (value < 0 || value > 127)
		std::cout << "impossible";
	else if (value < 32 || value == 127)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void printInt(double value, bool impossible)
{
	std::cout << "int: ";
	if (impossible || std::isnan(value) || std::isinf(value))
		std::cout << "impossible";
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (std::isnan(f))
		std::cout << "nanf";
	else if (std::isinf(f))
	{
		if (f > 0)
			std::cout << "+inff";
		else
			std::cout << "-inff";
	}
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	std::cout << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf";
		else
			std::cout << "-inf";
	}
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	int		type = detectType(input);
	double	value = 0;
	bool	impossible = false;

	if (type == -1)
	{
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}
	switch (type)
	{
		case 0:
		{
			char	c;
			if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
				c = input[1];
			else
				c = input[0];
			value = static_cast<double>(c);
			break;
		}
		case 1:
		{
			char *endptr;
			long l = strtol(input.c_str(), &endptr, 10);
			if (l < INT_MIN || l > INT_MAX)
			{
				impossible = true;
				value = 0;
			}
			else
				value = static_cast<double>(l);
			break;
		}
		case 2:
			if (input == "nanf")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (input == "+inff")
				value = std::numeric_limits<double>::infinity();
			else if (input == "-inff")
				value = -std::numeric_limits<double>::infinity();
			else
			{
				std::string withoutF = input.substr(0, input.length() - 1);
				value = strtod(withoutF.c_str(), NULL);
			}
			break;
		case 3:
			if (input == "nan")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (input == "+inf")
				value = std::numeric_limits<double>::infinity();
			else if (input == "-inf")
				value = -std::numeric_limits<double>::infinity();
			else
				value = strtod(input.c_str(), NULL);
			break;
	}

	printChar(value, impossible);
	printInt(value, impossible);
	printFloat(value);
	printDouble(value);
}
