#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	LogLevelMap loglevel_dict[4] = {
		{"DEBUG", loglv_debug},
		{"INFO", loglv_info},
		{"WARNING", loglv_warning},
		{"ERROR", loglv_error},
	};

	LogLevel log_level = loglv_no_logging;
	for (size_t i = 0; i < sizeof(loglevel_dict) / sizeof(LogLevelMap); i++)
	{
		if (loglevel_dict[i].level_str == level)
		{
			log_level = loglevel_dict[i].level;
			break;
		}
	}
	switch(log_level)
	{
		case loglv_debug:
			debug();
			// FALLTHROUGH
		case loglv_info:
			info();
			// FALLTHROUGH
		case loglv_warning:
			warning();
			// FALLTHROUGH
		case loglv_error:
			error();
			break;
		case loglv_no_logging:
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}