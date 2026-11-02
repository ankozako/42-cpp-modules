#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
	
		static std::vector<size_t> generateJS(size_t n);
		static std::vector<size_t> generateInsertionOrder(size_t n);

		static void mergeInsertSortVector(std::vector<int> &data);
		static void mergeInsertSortDeque(std::deque<int> &data);

		static void binaryInsertVector(std::vector<int> &sorted, int value);
		static void binaryInsertDeque(std::deque<int> &sorted, int value);
		
		static std::vector<int> parseInput(int argc, char **argv);
		static void printContainer(std::vector<int> const &data, std::string const &label);
	
	public:
		static void sort(int argc, char **argv);
};

#endif