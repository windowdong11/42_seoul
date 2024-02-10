#ifndef SOCKET_HPP
#define SOCKET_HPP

/* include headers */
#include "SocketControlBlock.hpp"
class SocketControlBlock;

class Socket
{
private:
	/* DO NOT CALL THIS */
	Socket();

public:
	Socket(int fd);
	Socket(const Socket &other);
	Socket &operator=(const Socket &other);
	~Socket();
	int bind(int port);
	int listen(int backlog);
	void close();
	bool isOpen();
	int getSocketFd();
	int accept();
	int read(char *buffer, int size);
	int write(const char *buffer, int size);

private:
	SocketControlBlock *mControlBlock;
};

#endif
