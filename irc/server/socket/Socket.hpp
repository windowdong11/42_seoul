#ifndef SOCKET_HPP
#define SOCKET_HPP

/* include headers */
#include "SocketControlBlock.hpp"
class SocketControlBlock;

class Socket
{
private:
	SocketControlBlock *mControlBlock;

	/* DO NOT CALL THIS */
	Socket();

public:
	Socket(int fd);
	Socket(const Socket &other);
	Socket &operator=(const Socket &other);
	~Socket();
	void bind(int port);
	void listen(int backlog);
	void close();
	bool isOpen();
	int getSocketFd();
};

#endif
