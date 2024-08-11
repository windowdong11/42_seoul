#include "ScalarConverter.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) { (void)rhs; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
  (void)rhs;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

namespace
{
  bool isPrintableChar(std::string str)
  {
    return str.length() == 3 && str[0] == '\'' && str[2] == '\'' &&
           std::isprint(str[1]);
  }

  bool isInt(std::string str)
  {
    std::stringstream ss(str);
    int num;
    ss >> num;
    if (ss.fail() || !ss.eof())
      return false;
    return true;
  }

  bool isDouble(std::string str)
  {
    if (str == "+inf" || str == "-inf" || str == "nan")
      return true;
    if (str.length() < 3)
      return false;
    std::string::const_iterator it = str.begin();
    if (*it == '+' || *it == '-')
    {
      if (it + 1 == str.end())
        return false;
      ++it;
    }
    bool isDotUsed = false;
    std::string::const_iterator it_end = str.end() - 1;
    while (it != it_end)
    {
      if (*it == '.')
      {
        if (isDotUsed || it + 1 == str.end() || !::isdigit(*(it + 1)) ||
            it == str.begin() || !::isdigit(*(it - 1)))
          return false;
        isDotUsed = true;
      }
      else if (!::isdigit(*it))
        return false;
      ++it;
    }
    if (!isDotUsed)
      return false;
    return true;
  }

  bool isFloat(std::string str)
  {
    if (str[str.length() - 1] == 'f')
    {
      str = str.substr(0, str.length() - 1);
      return isDouble(str);
    }
    return false;
  }
}

ScalarConverter::eType ScalarConverter::detectType(std::string str)
{
  if (isPrintableChar(str))
    return CHAR;
  if (isInt(str))
    return INT;
  if (isFloat(str))
    return FLOAT;
  if (isDouble(str))
    return DOUBLE;
  return NONE;
}

char ScalarConverter::toChar(std::string str)
{
  return str[1];
}

int ScalarConverter::toInt(std::string str)
{
  int num;
  std::stringstream ss(str);
  ss >> num;
  return num;
}

float ScalarConverter::toFloat(std::string str)
{
  if (str == "+inff")
  {
    return std::numeric_limits<float>::infinity();
  }
  else if (str == "-inff")
  {
    return -std::numeric_limits<float>::infinity();
  }
  else if (str == "nanf")
  {
    return std::numeric_limits<float>::quiet_NaN();
  }
  else
  {
    str = str.substr(0, str.length() - 1); // remove 'f' from the end of the string
    float flt;
    std::stringstream ss(str);
    ss >> flt;
    return flt;
  }
}

double ScalarConverter::toDouble(std::string str)
{
  if (str == "+inf")
  {
    return std::numeric_limits<double>::infinity();
  }
  else if (str == "-inf")
  {
    return -std::numeric_limits<double>::infinity();
  }
  else if (str == "nan")
  {
    return std::numeric_limits<double>::quiet_NaN();
  }
  else
  {
    double dbl;
    std::stringstream ss(str);
    ss >> dbl;
    return dbl;
  }
}

void ScalarConverter::convert(std::string str)
{
  char ch;
  int num;
  float flt;
  double dbl;
  eType type = detectType(str);

  switch (type)
  {
  case CHAR:
    ch = toChar(str);
    break;
  case INT:
    num = toInt(str);
    break;
  case FLOAT:
    flt = toFloat(str);
    break;
  case DOUBLE:
    dbl = toDouble(str);
    break;
  default:
    std::cout << "Error: invalid input" << std::endl;
    return;
  }

  std::cout << std::fixed << std::setprecision(1);
  switch (type)
  {
  case CHAR:
    std::cout << "char: '" << ch << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(ch) << std::endl;
    std::cout << "float: " << static_cast<float>(ch) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(ch) << std::endl;
    break;
  case INT:
    std::cout << "char: ";
    if (num < static_cast<int>(std::numeric_limits<char>::min()) ||
        num > static_cast<int>(std::numeric_limits<char>::max()))
    {
      std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(num))
    {
      std::cout << "Non displayable" << std::endl;
    }
    else
    {
      std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
    }
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
    break;
  case FLOAT:
    std::cout << "char: ";
    if (flt < static_cast<int>(std::numeric_limits<char>::min()) ||
        flt > static_cast<int>(std::numeric_limits<char>::max()) ||
        ::isnan(flt))
    {
      std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<char>(flt)))
    {
      std::cout << "Non displayable" << std::endl;
    }
    else
    {
      std::cout << "'" << static_cast<char>(flt) << "'" << std::endl;
    }
    std::cout << "int: ";
    if (flt < static_cast<float>(std::numeric_limits<int>::min()) ||
        flt > static_cast<float>(std::numeric_limits<int>::max()) ||
        ::isnan(flt))
    {
      std::cout << "impossible" << std::endl;
    }
    else
    {
      std::cout << static_cast<int>(flt) << std::endl;
    }
    std::cout << "float: " << flt << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(flt) << std::endl;
    break;
  case DOUBLE:
    std::cout << "char: ";
    if (dbl < static_cast<double>(std::numeric_limits<char>::min()) ||
        dbl > static_cast<double>(std::numeric_limits<char>::max()) ||
        ::isnan(dbl))
    {
      std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<char>(dbl)))
    {
      std::cout << "Non displayable" << std::endl;
    }
    else
    {
      std::cout << "'" << static_cast<char>(dbl) << "'" << std::endl;
    }
    std::cout << "int: ";
    if (dbl < static_cast<double>(std::numeric_limits<int>::min()) ||
        dbl > static_cast<double>(std::numeric_limits<int>::max()) ||
        ::isnan(dbl))
    {
      std::cout << "impossible" << std::endl;
    }
    else
    {
      std::cout << static_cast<int>(dbl) << std::endl;
    }
    std::cout << "float: ";
    if (dbl < static_cast<double>(-std::numeric_limits<float>::max()) ||
        dbl > static_cast<double>(std::numeric_limits<float>::max()))
    {
      std::cout << "impossible" << std::endl;
    }
    else
    {
      std::cout << static_cast<float>(dbl) << "f" << std::endl;
    }
    std::cout << "double: " << dbl << std::endl;
    break;
  default:
    std::cout << "Error: invalid input" << std::endl;
    return;
  }
}
