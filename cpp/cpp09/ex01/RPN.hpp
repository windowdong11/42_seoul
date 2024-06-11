#ifndef RPN_HPP
#define RPN_HPP

/* include */
#include "Result.tpp"
#include <string>
#include <stack>
#include <queue>

class RPN
{
public:
	typedef Result<int> RPNResult;
	static RPNResult calculate(const std::string& expression);
private:
	RPN();
	RPN(const RPN &rhs);
	RPN &operator=(const RPN &rhs);
	~RPN();
};

#endif