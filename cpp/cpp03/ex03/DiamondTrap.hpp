#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

/* include headers */
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/* code */
class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap &operator=(const DiamondTrap& other);
	~DiamondTrap();

	// override
	DiamondTrap(const std::string& name);
	void attack(const std::string& target);

	void whoAmI();
};


#endif