#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		static std::map<std::string, double> _prices;
		static void loadDatabase(std::string const &filename);
		static bool isValidDate(std::string const &date);
		static bool isValidValue(std::string const &valueStr, double &value);
		static double getExchangeRate(std::string const &date);
		static void processLine(std::string const &line);
	public:
		static void processFile(std::string const &filename);
};

#endif