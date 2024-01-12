#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

#ifndef DEBUG_BRAIN
#define DEBUG_BRAIN 0
#endif

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& rhs);
	Brain& operator=(const Brain& rhs);
	~Brain();
};

#endif