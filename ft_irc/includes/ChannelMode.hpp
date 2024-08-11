#pragma once
#ifndef CHANNELMODE_HPP
# define CHANNELMODE_HPP

enum ChannelMode
{
	M_FLAG_CHANNEL_DOES_NOT_EXIST		= 1 << 0,
	M_FLAG_CHANNEL_INVITE_ONLY			= 1 << 1,
	M_FLAG_CHANNEL_TOPIC_OPERATOR_ONLY	= 1 << 2,
	M_FLAG_CHANNEL_PASSWORD_CHECK_ON	= 1 << 3,
	M_FLAG_CHANNEL_MAX_USER_LIMIT_ON	= 1 << 4,
};
#endif