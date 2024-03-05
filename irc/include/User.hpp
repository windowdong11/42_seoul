#ifndef USER_HPP
#define USER_HPP

/* include headers */
#include <string>
#include "Socket.hpp"

class User
{
public:
	enum eRole
	{
		ROLE_OP = 0,
		ROLE_NORMAL = 1
	};

public:
	User();
	User(int fd);
	User(const User &other);
	User &operator=(const User &other);
	~User();
	std::string getUsername() const;
	std::string getNickname() const;
	std::string getPassword() const;
	User::eRole getRole() const;
	Socket &getSocket();
	void setUsername(std::string username);
	void setNickname(std::string nickname);
	void setPassword(std::string password);
	void setRole(User::eRole role);

private:
	std::string mUsername;
	std::string mNickname;
	std::string mPassword;
	User::eRole mRole;
	Socket mSocket;
};

#endif
