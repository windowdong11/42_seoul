#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(const RPN &rhs)
{
	(void)rhs;
};

RPN &RPN::operator=(const RPN &rhs)
{
	(void)rhs;
	return *this;
};

RPN::~RPN(){};

RPN::RPNResult RPN::calculate(const std::string& expression)
{
	std::stack<int> stack;
	// 단위 = 공백/끝 숫자/문자 [단위]
	// 줄 = 숫자/문자 [단위]
	for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it)
	{
		if (*it == ' ')
			continue;
		if ('0' <= *it && *it <= '9')
		{
			stack.push(*it - '0');
			if (it + 1 != expression.end() && *(it + 1) != ' ')
			{
				// Wrong expression. Need to be space between numbers.
				return RPNResult(RPNResult::FAIL, 0);
			}
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (stack.size() < 2)
			{
				// Wrong expression. Need two numbers to calculate.
				return RPNResult(RPNResult::FAIL, 0);
			}
			int right = stack.top();
			stack.pop();
			int left = stack.top();
			stack.pop();
			if (*it == '+')
				stack.push(left + right);
			else if (*it == '-')
				stack.push(left - right);
			else if (*it == '*')
				stack.push(left * right);
			else if (*it == '/')
			{
				if (right == 0)
				{
					// Wrong expression. Need to be non-zero number to divide.
					return RPNResult(RPNResult::FAIL, 0);
				}
				else
				{
					stack.push(left / right);
				}
			}
		}
		else
		{
			// Wrong character. Need to be number or operator or space.
			return RPNResult(RPNResult::FAIL, 0);
		}
	}
	if (stack.size() != 1)
	{
		// Wrong expression. Need to be only one number in stack.
		return RPNResult(RPNResult::FAIL, 0);
	}
	return RPNResult(RPNResult::SUCCESS, stack.top());
}