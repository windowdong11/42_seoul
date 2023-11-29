#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
private:
	void debug();
	void info();
	void warning();
	void error();
	typedef void (Harl::* t_action)();
	struct DispatchTable {
		const std::string level;
		const t_action action;
	};
public:
	Harl();
	~Harl();
	void complain(std::string level);
};


#endif