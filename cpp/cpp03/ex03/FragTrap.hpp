#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

/* include headers */
#include "ClapTrap.hpp"

/* code */
class FragTrap : virtual public ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap &operator=(const FragTrap& other);
	~FragTrap();

	// override
	FragTrap(const std::string& name);

	void highFiveGuys(void);
};


#endif