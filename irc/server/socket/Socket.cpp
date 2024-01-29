#include "Socket.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdexcept>
#include <cstring>
#include <unistd.h>

Socket::Socket(int port) : mControlBlock(new SocketControlBlock(::socket(PF_INET, SOCK_STREAM, 0)))
{
	if (mControlBlock->getSocket() == -1)
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

void Socket::bind(int port)
{
	sockaddr_in mServerAddr;
	std::memset(&mServerAddr, 0, sizeof(mServerAddr));
	mServerAddr.sin_family = AF_INET;
	mServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	mServerAddr.sin_port = htons(port);
	if (::bind(mControlBlock->getSocket(), (struct sockaddr *)&mServerAddr, sizeof(mServerAddr)) == -1)
		throw std::runtime_error("Failed to bind socket.");
}

void Socket::listen(int backlog)
{
	if (::listen(mControlBlock->getSocket(), 5) == -1)
		throw std::runtime_error("Failed to listen socket");
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
