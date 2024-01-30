#ifndef CHANNEL_HPP
#define CHANNEL_HPP

/* include headers */
#include <string>
#include <vector>

class User;

class Channel
{
public:
	Channel();
	Channel(const Channel &other);
	Channel &operator=(const Channel &other);
	~Channel();

private:
	std::string mChannelName;
	std::vector<User *> mUsers;
};

#endif
