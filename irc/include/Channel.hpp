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
		CHANNEL_MODE_SECRET = 1 << 0,
		CHANNEL_MODE_INVITE = 1 << 1,
	};

public:
	Channel();
	Channel(User *op, std::string channelName);
	Channel(const Channel &other);
	Channel &operator=(const Channel &other);
	~Channel();
	void setChannelName(std::string channelName);
	void addOperator(User *user);
	bool removeOperator(User *user);

	std::string getChannelName() const;
	void addUser(User *user);
	bool removeUser(User *user);
	User *findUser(const User *const user) const;
	std::vector<User *> getOperators() const;
	void addMode(Channel::eChannelMode mode);
	void removeMode(Channel::eChannelMode mode);
	Channel::eChannelMode getMode() const;

private:
	std::string mChannelName;
	std::vector<User *> mUsers;
	std::vector<User *> mOperators;
	Channel::eChannelMode mMode;
};

#endif
