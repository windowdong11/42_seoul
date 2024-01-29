#ifndef CHANNEL_HPP
#define CHANNEL_HPP

/* include headers */
#include <string>

class Channel
{
public:
	Channel();
	Channel(const Channel &other);
	Channel &operator=(const Channel &other);
	~Channel();

private:
	std::string mChannelName;
};

#endif
