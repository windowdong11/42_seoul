class Fixed
{
private:
	int fixed;
	static const int fraction;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed& other);
	~Fixed();
};
