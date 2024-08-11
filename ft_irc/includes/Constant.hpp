#pragma once
#ifndef CONSTANT_HPP
# define CONSTANT_HPP

enum Constant
{
	M_IRC_MAX_MESSAGE_LENGTH			= 512,
	M_SERVER_READ_BUFFER_SIZE			= 1024,
	M_SERVER_LISTEN_BACKLOG_QUEUE_SIZE	= 10,
	M_SERVER_KQUEUE_EVENT_BUFFER_SIZE	= 10,
	M_SERVER_CONNECTION_TIMEOUT_SECONDS	= 10,
};
#endif