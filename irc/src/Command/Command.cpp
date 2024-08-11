#include <string>
#include "Command.hpp"
#include "Message.hpp"

std::map<std::string, Command::CommandFunction> Command::mHookList;

Command::Command(void) {}
Command::Command(const Command& source) { (void)source; }
Command&	Command::operator=(const Command& source)
{ if (this != &source) { } return (*this); }
Command::~Command(void) {}

void	Command::RegisterCommand(const std::string& command,
								 CommandFunction function)
{
	mHookList[command] = function;
}

bool	Command::ExecuteCommand(const Message& message)
{
	std::map<std::string, CommandFunction>::iterator	it
		= mHookList.find(message.GetCommand());

	if (it != mHookList.end())
	{
		try { (*it->second)(message); } catch (...) {}
		return (false);
	}
	return (true);
}
