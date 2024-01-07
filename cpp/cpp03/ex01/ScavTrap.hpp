#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/* include headers */
#include "ClapTrap.hpp"

/* code */
class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap &operator=(const ScavTrap& other);
	~ScavTrap();

	// override
	ScavTrap(const std::string& name);
	void attack(const std::string &target);

	void guardGate();
};


#endif