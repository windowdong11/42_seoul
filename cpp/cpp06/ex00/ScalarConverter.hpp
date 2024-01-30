#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& rhs);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	virtual ~ScalarConverter() = 0;
	static void convert(std::string str);
};

#endif