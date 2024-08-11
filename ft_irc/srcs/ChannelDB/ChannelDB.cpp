#include <stdexcept>
#include <cstddef>
#include <sstream>
#include "ChannelDB.hpp"
#include "Channel.hpp"
#include "UserDB.hpp"
#include "ChannelMode.hpp"

namespace
{
	ChannelDB*	TouchInstanceData(ChannelDB* address);
}

ChannelDB::ChannelDB(void)
{
	TouchInstanceData(this);
}

ChannelDB::~ChannelDB(void) {}

int	ChannelDB::CreateChannel(const std::string& name)
{
	RefDB::iterator	it = mReferenceTableName.find(name);

	if (it != mReferenceTableName.end())
	{
		return (-1);
	}

	int	channelId = mIndex.GetNewIndex();

	if (channelId < 0)
	{
		return (-1);
	}

	std::pair<DB::iterator, bool>	result
		= mDataBase.insert(std::make_pair(channelId,
										  Channel(channelId, name)));

	if (result.second)
	{
		mReferenceTableName[name] = channelId;
		return (channelId);
	}
	return (-1);
}

void	ChannelDB::DeleteChannel(int channelId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}
	mIndex.DeactivateIndex(channelId);

	mDataBase.erase(it);
	mReferenceTableName.erase(it->second.GetChannelName());
	UserDB::GetInstance().RemoveChannelInAllUsers(channelId);
}

bool	ChannelDB::IsChannelIdValid(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (false);
	}
	return (true);
}

bool	ChannelDB::IsUserInChannel(int channelId, int userId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (false);
	}
	return (it->second.IsUserActive(userId));
}

bool	ChannelDB::AddUserIntoChannel(int channelId, int userId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (false);
	}
	bool isUserInChannel = it->second.AddActiveUser(userId);
	if (isUserInChannel)
	{


		UserDB::GetInstance().WriteChannelInUserData(userId, channelId);
	}

	return (isUserInChannel);
}

void	ChannelDB::RemoveUserFromChannel(int channelId, int userId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}

	if (it->second.RemoveUserData(userId))
	{

		UserDB::GetInstance().RemoveChannelInUserList(userId, channelId);
	}
}

bool	ChannelDB::AddOperatorIntoChannel(int channelId, int userId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (false);
	}

	bool isUserOperator = it->second.AddOperator(userId);
	return (isUserOperator);
}

void	ChannelDB::RemoveOperatorFromChannel(int channelId, int userId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}
	it->second.RemoveOperator(userId);
}

bool	ChannelDB::IsUserOperator(int channelId, int userId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (false);
	}
	return (it->second.IsUserOperator(userId));
}

void	ChannelDB::AddInvitedUserIntoChannel(int channelId, int userId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}

	it->second.AddInvitedUser(userId);
}

void	ChannelDB::RemoveInvitedUserFromChannel(int channelId, int userId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}
	it->second.RemoveInvitedUser(userId);
}

bool	ChannelDB::IsUserInvited(int channelId, int userId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (false);
	}
	return (it->second.IsUserInvited(userId));
}

void	ChannelDB::DeleteUserInAllChannels(int userId)
{
	for (DB::iterator it = mDataBase.begin(); it != mDataBase.end(); ++it)
	{
		it->second.RemoveUserData(userId);
	}
}

int	ChannelDB::GetChannelIdByName(const std::string& name) const
{
	RefDB::const_iterator	it = mReferenceTableName.find(name);

	if (it == mReferenceTableName.end())
	{
		return (-1);
	}
	return (it->second);
}

void	ChannelDB::SetChannelFlag(int channelId, unsigned int flag)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}
	it->second.SetChannelMode(flag);
}

unsigned int	ChannelDB::GetChannelFlag(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (M_FLAG_CHANNEL_DOES_NOT_EXIST);
	}
	return (it->second.GetChannelMode());
}

void	ChannelDB::AddChannelFlag(int channelId, unsigned int flag)
{
	SetChannelFlag(channelId, GetChannelFlag(channelId) | flag);
}

void	ChannelDB::RemoveChannelFlag(int channelId, unsigned int flag)
{
	SetChannelFlag(channelId, GetChannelFlag(channelId) & ~flag);
}

void	ChannelDB::SetChannelName(int channelId, const std::string& name)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}
	it->second.SetChannelName(name);
}

std::string	ChannelDB::GetChannelName(int channelId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ("");
	}
	return (it->second.GetChannelName());
}

void	ChannelDB::SetChannelPassword(int channelId, const std::string& password)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}
	it->second.SetPassword(password);
}

std::string	ChannelDB::GetChannelPassword(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ("");
	}
	return (it->second.GetPassword());
}

void	ChannelDB::SetChannelTopic(int channelId, const std::string& topic, int setUserId)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}
	it->second.SetTopic(topic, setUserId);
}

std::string	ChannelDB::GetChannelTopic(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ("");
	}
	return (it->second.GetTopic());
}

int	ChannelDB::GetChannelTopicSetUser(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (-1);
	}
	return (it->second.GetTopicSetUserId());
}

std::time_t	ChannelDB::GetCreatedTimeOfChannel(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (static_cast<std::time_t>(-1));
	}
	return (it->second.GetCreatedTime());
}

std::string	ChannelDB::GetCreatedTimeStampOfChannel(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ("");
	}

	std::ostringstream	oss;
	oss << it->second.GetCreatedTime();
	return (oss.str());
}

ChannelDB::UserList	ChannelDB::GetUserListInChannel(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (UserList());
	}
	return (it->second.GetActiveUserList());
}

ChannelDB::UserList	ChannelDB::GetOperatorListInChannel(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (UserList());
	}
	return (it->second.GetOperatorList());
}

ChannelDB::UserList	ChannelDB::GetBanListInChannel(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (UserList());
	}
	return (it->second.GetBanUserList());
}

void	ChannelDB::AnnounceToChannel(const std::string& message,
										int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}

	UserList	list = it->second.GetActiveUserList();
	for (UserList::const_iterator lit = list.cbegin(); lit != list.cend(); ++lit)
	{
		UserDB::GetInstance().SendMessageToUser(message, *lit);
	}
}

void	ChannelDB::AnnounceErrorToChannel(const std::string& message,
											 int channelId, int code) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}

	UserList	list = it->second.GetActiveUserList();
	for (UserList::const_iterator lit = list.cbegin(); lit != list.cend(); ++lit)
	{
		UserDB::GetInstance().SendErrorMessageToUser(message, *lit, code, *lit);
	}
}

void	ChannelDB::AnnounceErrorToChannel(const std::string& message,
											 int channelId, int code,
											 int userId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}

	UserList	list = it->second.GetActiveUserList();
	for (UserList::const_iterator lit = list.cbegin(); lit != list.cend(); ++lit)
	{
		UserDB::GetInstance().SendErrorMessageToUser(message, userId, code, *lit);
	}
}

void	ChannelDB::AnnounceFormattedToChannel(const std::string& message,
												 int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}

	UserList	list = it->second.GetActiveUserList();
	for (UserList::const_iterator lit = list.cbegin(); lit != list.cend(); ++lit)
	{
		UserDB::GetInstance().SendFormattedMessageToUser(message, *lit, *lit);
	}
}

void	ChannelDB::AnnounceFormattedToChannel(const std::string& message,
												 int channelId, int userId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return ;
	}

	UserList	list = it->second.GetActiveUserList();
	for (UserList::const_iterator lit = list.cbegin(); lit != list.cend(); ++lit)
	{
		UserDB::GetInstance().SendFormattedMessageToUser(message, userId, *lit);
	}
}

bool	ChannelDB::SetMaxUsersInChannel(int channelId,
										unsigned int limit)
{
	DB::iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (false);
	}
	bool	isValueSetSuccessful = it->second.SetMaxActiveUsers(limit);
	return (isValueSetSuccessful);
}

unsigned int	ChannelDB::GetMaxUsersInChannel(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (-1);
	}
	return (it->second.GetMaxActiveUsers());
}

unsigned int	ChannelDB::GetCurrentUsersInChannel(int channelId) const
{
	DB::const_iterator	it = mDataBase.find(channelId);

	if (it == mDataBase.end())
	{
		return (-1);
	}
	return (it->second.GetCurrentActiveUsers());
}

ChannelDB& ChannelDB::GetInstance(void)
{
	ChannelDB*	output = TouchInstanceData(NULL);

	if (output == NULL)
		throw std::runtime_error("Channel Database Not Found");
	return (*output);
}

namespace
{
	ChannelDB*	TouchInstanceData(ChannelDB* address)
	{
		static ChannelDB*	ChannelDBGlobal = NULL;

		if (address != NULL)
		{
			ChannelDBGlobal = address;
			return (NULL);
		}

		return (ChannelDBGlobal);
	}
}

void	ChannelDB::DoNothing(void) const {}
ChannelDB::ChannelDB(const ChannelDB& source) { (void)source; }
ChannelDB&	ChannelDB::operator=(const ChannelDB& source)
{ if (this != &source) {} return (*this); }
