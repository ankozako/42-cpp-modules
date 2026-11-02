/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:15:08 by ankozako          #+#    #+#             */
/*   Updated: 2026/02/04 10:15:10 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string	replaceAll(const std::string& line, const std::string& toFind, const std::string& toReplace)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = line.find(toFind, pos)) != std::string::npos)
	{
		result.append(line, pos, found - pos);
		result.append(toReplace);
		pos = found + toFind.length();
	}
	result.append(line, pos, line.length() - pos);
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << "<filename> <s1> <s2>" <<std::endl;
		return (1);
	}

	std::string	filename = av[1];
	std::string	toFind = av[2];
	std::string	toReplace = av[3];

	if (toFind.empty())
	{
		std::cerr << "Error: Search string cannot be empty" << std::endl;
		return (1);
	}
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Cannot open file" << std::endl;
		return (1);
	}
	std::string	outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Cannot create file: " << outputFilename << std::endl;
		inputFile.close();
		return (1);
	}
	std::string	line;
	bool		firstLine = true;
	while (std::getline(inputFile, line))
	{
		if (!firstLine)
			outputFile << "\n";
		firstLine = false;
		outputFile << replaceAll(line, toFind, toReplace);
	}
	inputFile.close();
	outputFile.close();
	return (0);
}