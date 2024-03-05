#ifndef CHANNEL_HPP
#define CHANNEL_HPP

/* include headers */
#include <string>
#include <vector>
#include "User.hpp"

class User;

class Channel
{
public:
	enum eChannelMode
	{
		CHANNEL_MODE_NORMAL = 0,
		CHANNEL_MODE_SECRET = 1,
		CHANNEL_MODE_INVITE = 2,
	};

public:
	Channel();
	Channel(User *op, std::string channelName);
	Channel(const Channel &other);
	Channel &operator=(const Channel &other);
	~Channel();
	void setChannelName(std::string channelName);
	void setOperator(User *user);
	void addUser(User *user);
	void removeUser(const std::string& nickname);
	void changeMode(Channel::eChannelMode mode);
	
	std::string getChannelName() const;
	User *findUser(const std::string& nickname) const;
	User *getOperator() const;
	Channel::eChannelMode getMode() const;

private:
	std::string mChannelName;
	std::vector<User*> mUsers;
	User *mOperator;
	Channel::eChannelMode mMode;
};

#endif
