#ifndef FIXED_HPP
# define FIXED_HPP

#define COLOR_RESET "\033[0m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_BLUE "\033[34m"

#ifndef PRINT_STRUCTOR_LOGS
	#define PRINT_STRUCTOR_LOGS 0
#endif

#include <ostream>
class Fixed
{
private:
	int raw_fixed;
	static const int fraction;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	// ----------------- ex01 -----------------
	Fixed(const int integer);
	Fixed(const float floating);
	float toFloat(void) const;
	int toInt(void) const;

	// ----------------- ex02 -----------------
	bool operator>(const Fixed& rhs) const;
	bool operator<(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
