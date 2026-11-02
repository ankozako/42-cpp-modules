#include "RPN.hpp"
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isNumber(std::string const &token)
{
	if (token.length() != 1)
		return false;
	return (token[0] >= '0' && token[0] <= '9');
}

bool RPN::isOperator(std::string const &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperator(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return (a / b);
		default:
			throw std::runtime_error("Error");
	}
}

int RPN::evaluate(std::string const &expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			int value = token[0] - '0';
			stack.push(value);
		}
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error");
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result = applyOperator(a, b, token[0]);
			stack.push(result);
		}
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	return stack.top();
}
