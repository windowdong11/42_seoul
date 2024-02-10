#ifndef SOCKET_HPP
#define SOCKET_HPP
#include <type_traits>

/* include headers */
#include "SocketControlBlock.hpp"
#include <unistd.h>
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	bool operator==(uintptr_t fd) const;
=======
	bool operator==(uintptr_t fd) {
		return ((uintptr_t)mControlBlock->getSocket() == fd);
	}
>>>>>>> Stashed changes
=======
	bool operator==(uintptr_t fd) {
		return ((uintptr_t)mControlBlock->getSocket() == fd);
	}
>>>>>>> Stashed changes

private:
	SocketControlBlock *mControlBlock;
};

#endif
