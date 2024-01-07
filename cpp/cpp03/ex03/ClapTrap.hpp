#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define COLOR_RESET "\033[0m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_BLUE "\033[34m"

/* include headers */
#include <string>

/* code */
class ClapTrap
{
protected:
	std::string name;
	unsigned int health, energy, damage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	ClapTrap(const std::string& name);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif