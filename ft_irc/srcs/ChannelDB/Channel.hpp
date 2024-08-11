#pragma once
#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <ctime>
# include <string>
# include <set>
# include <vector>

class Channel
{
	public:
		typedef std::set<int>	DB;

		Channel(void);
		Channel(int channelId, const std::string& channelName);
		Channel(const Channel& source);
		Channel&	operator=(const Channel& source);
		~Channel(void);


		bool				SetMaxActiveUsers(unsigned int maxUsers);
		unsigned int		GetMaxActiveUsers(void) const;
		unsigned int		GetCurrentActiveUsers(void) const;

		bool				RemoveUserData(int userId);

		bool				AddActiveUser(int userId);
		void				RemoveActiveUser(int userId);
		bool				IsUserActive(int userId) const;


		bool				AddOperator(int userId);
		void				RemoveOperator(int userId);
		bool				IsUserOperator(int userId) const;


		void				AddInvitedUser(int userId);
		void				RemoveInvitedUser(int userId);
		bool				IsUserInvited(int userId) const;

		void				AddBanUser(int userId);
		void				RemoveBanUser(int userId);
		bool				IsUserBanned(int userId) const;

		void				SetChannelId(int id);
		unsigned int		GetChannelId(void) const;

		void				SetChannelName(const std::string& name);
		std::string&		GetChannelName(void);
		const std::string&	GetChannelName(void) const;

		void				SetChannelMode(unsigned int mode);
		unsigned int		GetChannelMode(void) const;

		void				SetPassword(const std::string& password);
		std::string&		GetPassword(void);
		const std::string&	GetPassword(void) const;

		void				SetTopic(const std::string& topic, int userId);
		std::string&		GetTopic(void);
		const std::string&	GetTopic(void) const;
		int					GetTopicSetUserId(void) const;
		std::time_t			GetCreatedTime(void) const;

		std::vector<int>	GetActiveUserList(void) const;
		std::vector<int>	GetOperatorList(void) const;
		std::vector<int>	GetInvitedUserList(void) const;
		std::vector<int>	GetBanUserList(void) const;

	private:
		int				mChannelId;
		std::string		mName;
		unsigned int	mChannelMode;
		unsigned int	mMaxActiveUsers;
		unsigned int	mCurrentActiveUsers;
		std::string		mPassword;
		std::string		mTopic;
		int				mTopicSetUser;
		std::time_t		mCreatedTime;

		DB				mActiveUserList;
		DB				mOperatorList;
		DB				mInvitedUserList;
		DB				mBanUserList;
};
#endif
