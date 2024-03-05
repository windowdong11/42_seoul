#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
  enum eType
	{
		NONE,
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
	};
	ScalarConverter();
	ScalarConverter(const ScalarConverter& rhs);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter();
	static eType detectType(std::string str);
	static char toChar(std::string str);
	static int toInt(std::string str);
	static float toFloat(std::string str);
	static double toDouble(std::string str);
public:
	static void convert(std::string str);
};

#endif