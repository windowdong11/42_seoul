#define COLOR_RESET "\033[0m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_BLUE "\033[34m"
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
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
