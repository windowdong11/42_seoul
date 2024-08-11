#include "User.hpp"

User::User() : mRole(ROLE_NORMAL), mSocket(-1)
{
}

User::User(int fd)
		: mRole(ROLE_NORMAL), mSocket(fd)
{
}

User::User(const User &other)
		: mUsername(other.mUsername), mNickname(other.mNickname), mPassword(other.mPassword), mRole(other.mRole), mSocket(other.mSocket)
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
	}
	return *this;
}

User::~User()
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

std::string User::getPassword() const
{
	return mPassword;
}

User::eRole User::getRole() const
{
	return mRole;
}

Socket &User::getSocket()
{
	return mSocket;
}

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
