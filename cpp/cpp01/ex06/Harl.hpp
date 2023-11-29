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
	enum LogLevel
	{
		loglv_no_logging = -1,
		loglv_debug = 0,
		loglv_info,
		loglv_warning,
		loglv_error,
	};
	struct LogLevelMap
	{
		std::string level_str;
		LogLevel level;
	};
public:
	Harl();
	~Harl();
	void complain(std::string level);
};


#endif