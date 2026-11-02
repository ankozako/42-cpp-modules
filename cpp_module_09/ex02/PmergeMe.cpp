#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <sys/time.h>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

std::vector<size_t> PmergeMe::generateJS(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0)
		return jacobsthal;
	jacobsthal.push_back(0);
	if (n == 1)
		return jacobsthal;
	jacobsthal.push_back(1);
	while (true)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >= n)
			break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t n)
{
	std::vector<size_t> order;
	if (n == 0)
		return order;
	std::vector<size_t> jacobsthal = generateJS(n);
	for (size_t i = 3; i < jacobsthal.size(); ++i)
	{
		size_t current = jacobsthal[i];
		size_t previous = jacobsthal[i - 1];
		for (size_t j = current; j > previous; --j)
		{
			if (j - 1 < n)
				order.push_back(j - 1);
		}
	}
	for (size_t i = 0; i < n; ++i)
	{
		if (std::find(order.begin(), order.end(), i) == order.end())
			order.push_back(i);
	}
	return order;
}

std::vector<int> PmergeMe::parseInput(int argc, char **argv)
{
	std::vector<int> data;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(arg[j]) && !std::isspace(arg[j]))
				throw std::runtime_error("Error");
		}
		std::istringstream iss(arg);
		int num;
		if (!(iss >> num))
			throw std::runtime_error("Error");
		if (num < 0)
			throw std::runtime_error("Error");
		data.push_back(num);
	}
	if (data.empty())
		throw std::runtime_error("Error");
	return data;
}

void PmergeMe::printContainer(std::vector<int> const &data, std::string const &label)
{
	std::cout << label;
	size_t limit = (data.size() > 5) ? 5 : data.size();
	for (size_t i = 0; i < limit; ++i)
		std::cout << data[i] << " ";
	if (data.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::binaryInsertVector(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &data)
{
	if (data.size() <= 1)
		return;
	std::vector<std::pair<int, int> > pairs;
	bool hasStray = (data.size() % 2 != 0);
	int stray = 0;
	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		int a = data[i];
		int b = data[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	if (hasStray)
		stray = data[data.size() - 1];
	std::vector<int> mainChain;
	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}
	mergeInsertSortVector(mainChain);
	if (!pending.empty())
		binaryInsertVector(mainChain, pending[0]);
	if (pending.size() > 1)
	{
		std::vector<size_t> insertionOrder = generateInsertionOrder(pending.size() - 1);
		for (size_t i = 0; i < insertionOrder.size(); ++i)
		{
			size_t idx = insertionOrder[i] + 1;
			if (idx < pending.size())
				binaryInsertVector(mainChain, pending[idx]);
		}
	}
	if (hasStray)
		binaryInsertVector(mainChain, stray);
	data = mainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &data)
{
	if (data.size() <= 1)
		return;
	std::vector<std::pair<int, int> > pairs;
	bool hasStray = (data.size() % 2 != 0);
	int stray = 0;
	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		int a = data[i];
		int b = data[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	if (hasStray)
		stray = data[data.size() - 1];
	std::deque<int> mainChain;
	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}
	mergeInsertSortDeque(mainChain);
	if (!pending.empty())
		binaryInsertDeque(mainChain, pending[0]);
	if (pending.size() > 1)
	{
		std::vector<size_t> insertionOrder = generateInsertionOrder(pending.size() - 1);
		for (size_t i = 0; i < insertionOrder.size(); ++i)
		{
			size_t idx = insertionOrder[i] + 1;
			if (idx < pending.size())
				binaryInsertDeque(mainChain, pending[idx]);
		}
	}
	if (hasStray)
		binaryInsertDeque(mainChain, stray);
	data = mainChain;
}

void PmergeMe::sort(int argc, char **argv)
{
	try
	{
		std::vector<int> data = parseInput(argc, argv);
		printContainer(data, "Before: ");
		std::vector<int> vectorData = data;
		struct timeval startTime, endTime;
		gettimeofday(&startTime, NULL);
		mergeInsertSortVector(vectorData);
		gettimeofday(&endTime, NULL);
		long seconds = endTime.tv_sec - startTime.tv_sec;
		long microseconds = endTime.tv_usec - startTime.tv_usec;
		double vectorTime = seconds * 1000000.0 + microseconds;

		std::deque<int> dequeData(data.begin(), data.end());
		gettimeofday(&startTime, NULL);
		mergeInsertSortDeque(dequeData);
		gettimeofday(&endTime, NULL);
		seconds = endTime.tv_sec - startTime.tv_sec;
		microseconds = endTime.tv_usec - startTime.tv_usec;
		double dequeTime = seconds * 1000000.0 + microseconds;
		printContainer(vectorData, "After: ");
		std::cout << "Time to process a range of " << data.size() << " elements with std::vector: " << vectorTime << " us" << std::endl;
		std::cout << "Time to process a range of " << data.size() << " elements with std::deque: " << dequeTime << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

