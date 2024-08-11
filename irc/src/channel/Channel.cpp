#include "Channel.hpp"

Channel::Channel()
		: mOperator(NULL), mMode(CHANNEL_MODE_NORMAL)
{
}

Channel::Channel(User *op, std::string channelName)
		: mChannelName(channelName), mOperator(op), mMode(CHANNEL_MODE_NORMAL)
{
}

Channel::Channel(const Channel &other)
		: mChannelName(other.mChannelName), mOperator(other.mOperator), mMode(other.mMode)
{
}

Channel &Channel::operator=(const Channel &other)
{
	if (this != &other)
	{
		mChannelName = other.mChannelName;
		mOperator = other.mOperator;
		mMode = other.mMode;
	}
	return *this;
}

Channel::Channel::~Channel()
{
}

void Channel::Channel::setChannelName(std::string channelName)
{
	mChannelName = channelName;
}

void Channel::Channel::setOperator(User *user)
{
	mOperator = user;
}

void Channel::Channel::addUser(User *user)
{
	mUsers.push_back(user);
}

void Channel::Channel::removeUser(const std::string &nickname)
{
	for (std::vector<User *>::iterator it = mUsers.begin(); it != mUsers.end(); ++it)
	{
		if ((*it)->getNickname() == nickname)
		{
			mUsers.erase(it);
			return;
		}
	}
}

void Channel::Channel::changeMode(Channel::eChannelMode mode)
{
	mMode = mode;
}

std::string Channel::Channel::getChannelName() const
{
	return mChannelName;
}

User *Channel::findUser(const std::string &nickname) const
{
	for (std::vector<User *>::const_iterator it = mUsers.begin(); it != mUsers.end(); ++it)
	{
		if ((*it)->getNickname() == nickname)
		{
			return *it;
		}
	}
	return NULL;
}

User *Channel::getOperator() const
{
	return mOperator;
}

Channel::eChannelMode Channel::getMode() const
{
	return mMode;
}
