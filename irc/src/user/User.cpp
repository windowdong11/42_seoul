#include "User.hpp"

<<<<<<< Updated upstream
User::User() : mRole(ROLE_NORMAL), mSocket(-1)
{
}

User::User(int fd)
		: mRole(ROLE_NORMAL), mSocket(fd)
=======
User::User() : mRole(ROLE_NORMAL)
>>>>>>> Stashed changes
{
}

User::User(const User &other)
<<<<<<< Updated upstream
		: mUsername(other.mUsername), mNickname(other.mNickname), mPassword(other.mPassword), mRole(other.mRole), mSocket(other.mSocket)
=======
		: mUsername(other.mUsername), mNickname(other.mNickname), mPassword(other.mPassword), mRole(other.mRole)
>>>>>>> Stashed changes
{
}

User &User::operator=(const User &other)
{
	if (this != &other)
	{
		mUsername = other.mUsername;
		mNickname = other.mNickname;
		mPassword = other.mPassword;
		mRole = other.mRole;
		mSocket = NULL;
	}
	return *this;
}

User::~User()
{
}

<<<<<<< Updated upstream
std::string User::getUsername() const
{
	return mUsername;
}

std::string User::getNickname() const
{
	return mNickname;
}

=======
User::User(Socket &socket)
	: mSocket(socket)
{
}

std::string User::getUsername() const
{
	return mUsername;
}

std::string User::getNickname() const
{
	return mNickname;
}

>>>>>>> Stashed changes
std::string User::getPassword() const
{
	return mPassword;
}

User::eRole User::getRole() const
{
	return mRole;
}

<<<<<<< Updated upstream
Socket &User::getSocket()
{
	return mSocket;
}

=======
>>>>>>> Stashed changes
void User::setUsername(std::string username)
{
	mUsername = username;
}

void User::setNickname(std::string nickname)
{
	mNickname = nickname;
}

void User::setPassword(std::string password)
{
	mPassword = password;
}

void User::setRole(User::eRole role)
{
	mRole = role;
}

int User::getSocketFd()
{
	if (mSocket == NULL)
	{
		return -1;
	}
	return mSocket.getSocketFd();
}
