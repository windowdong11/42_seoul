#include <algorithm>
#include "Channel.hpp"

<<<<<<< Updated upstream
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
=======
Channel::Channel::Channel(const Channel &other)
{
}

Channel &Channel::operator=(const Channel &other)
{
}

Channel::Channel::~Channel()
{
}

void Channel::Channel::setChannelName(std::string channelName)
{
}

void Channel::Channel::addOperator(User *user)
{
	mOperators.push_back(user);
}

bool Channel::removeOperator(User *user)
{
	std::vector<User *>::const_iterator opIter = std::find(mOperators.begin(), mOperators.end(), user);
	if (opIter != mOperators.end())
	{
		mOperators.erase(opIter);
>>>>>>> Stashed changes
	}
	return opIter != mOperators.end();
}

<<<<<<< Updated upstream
User *Channel::getOperator() const
{
	return mOperator;
}

=======
void Channel::Channel::addUser(User *user)
{
	mUsers.push_back(user);
}

bool Channel::removeUser(User *user)
{
	std::vector<User *>::const_iterator userIter = std::find(mUsers.begin(), mUsers.end(), user);
	if (userIter != mUsers.end())
	{
		mUsers.erase(userIter);
		removeOperator(user);
		return true;
	}
	return false;
}

void Channel::Channel::addMode(Channel::eChannelMode mode)
{
	mMode = static_cast<eChannelMode>(mMode | mode);
}

void Channel::removeMode(Channel::eChannelMode mode)
{
	mMode = static_cast<eChannelMode>(mMode & ~mode);
}

std::string Channel::Channel::getChannelName() const
{
	return mChannelName;
}

User *Channel::findUser(const User *const user) const
{
	std::vector<User *>::const_iterator userIter = std::find(mUsers.begin(), mUsers.end(), user);
	return userIter != mUsers.end() ? *userIter : NULL;
}

std::vector<User *> Channel::getOperators() const
{
	return mOperators;
}

>>>>>>> Stashed changes
Channel::eChannelMode Channel::getMode() const
{
	return mMode;
}
