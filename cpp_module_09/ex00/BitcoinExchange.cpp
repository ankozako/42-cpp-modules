#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

std::map<std::string, double> BitcoinExchange::_prices;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		double rate = std::atof(rateStr.c_str());
		_prices[date] = rate;
	}
	file.close();
}

bool BitcoinExchange::isValidDate(std::string const &date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 1000 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(std::string const &valueStr, double &value)
{
	char *endptr;
	value = std::strtod(valueStr.c_str(), &endptr);
	while (*endptr && std::isspace(*endptr))
		endptr++;
	if (*endptr != '\0')
		return false;
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}

double BitcoinExchange::getExchangeRate(std::string const &date)
{
	std::map<std::string, double>::iterator it = _prices.find(date);
	if (it != _prices.end())
		return it->second;
	it = _prices.lower_bound(date);
	if (it == _prices.begin())
		throw std::runtime_error("Error: date too early for database.");
	--it;
	return it->second;
}

void BitcoinExchange::processLine(std::string const &line)
{
	size_t pos = line.find(" | ");
	if (pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, pos);
	std::string valueStr = line.substr(pos + 3);
	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	double value;
	if (!isValidValue(valueStr, value))
		return;
	try
	{
		double rate = getExchangeRate(date);
		double result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void BitcoinExchange::processFile(std::string const &filename)
{
	try
	{
		loadDatabase("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
		processLine(line);
	file.close();
}