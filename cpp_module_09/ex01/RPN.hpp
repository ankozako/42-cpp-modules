#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <stdexcept>

class RPN
{
	private:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		static bool isOperator(std::string const &token);
		static bool isNumber(std::string const &token);
		static int applyOperator(int a, int b, char op);
	public:
		static int evaluate(std::string const &expression);

};

#endif