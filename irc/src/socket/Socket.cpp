#include "Socket.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdexcept>
#include <cstring>
#include <unistd.h>

Socket::Socket(int socketFd) : mControlBlock(new SocketControlBlock(socketFd))
{
	if (mControlBlock->getSocket() < 0)
	{
		delete mControlBlock;
		throw std::runtime_error("Failed to initialize socket. socket().");
	}
}

Socket::Socket(const Socket &other)
		: mControlBlock(mControlBlock)
{
	mControlBlock->increaseRefCnt();
}

Socket &Socket::operator=(const Socket &other)
{
	if (this != &other)
	{
		mControlBlock->decreaseRefCnt();
		if (mControlBlock->getRefCnt() == 0)
		{
			delete mControlBlock;
		}
		mControlBlock = other.mControlBlock;
		mControlBlock->increaseRefCnt();
	}
	return *this;
}

Socket::~Socket()
{
	mControlBlock->decreaseRefCnt();
	if (mControlBlock->getRefCnt() == 0)
	{
		delete mControlBlock;
	}
	mControlBlock = NULL;
}

int Socket::bind(int port)
{
	sockaddr_in mServerAddr;
	std::memset(&mServerAddr, 0, sizeof(mServerAddr));
	mServerAddr.sin_family = AF_INET;
	mServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	mServerAddr.sin_port = htons(port);
	return ::bind(mControlBlock->getSocket(), (struct sockaddr *)&mServerAddr, sizeof(mServerAddr));
}

int Socket::listen(int backlog)
{
	return ::listen(mControlBlock->getSocket(), 5);
}

void Socket::close()
{
	::close(mControlBlock->getSocket());
	mControlBlock->setSocket(-1);
}

bool Socket::isOpen()
{
	return mControlBlock->getSocket() >= 0;
}

int Socket::getSocketFd()
{
	return mControlBlock->getSocket();
}

int Socket::accept()
{
	return ::accept(mControlBlock->getSocket(), NULL, NULL);
}

int Socket::read(char *buffer, int size)
{
	return ::read(mControlBlock->getSocket(), buffer, size);
}

int Socket::write(const char *buffer, int size)
{
	return ::write(mControlBlock->getSocket(), buffer, size);
}
