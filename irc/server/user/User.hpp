#ifndef USER_HPP
#define USER_HPP

/* include headers */
#include <string>

class User
{
public:
	enum eRole
	{
		op = 0,
		normal = 1
	};

public:
	User();
	User(const User &other);
	User &operator=(const User &other);
	~User();
	std::string getUsername() const;
	std::string getNickname() const;
	std::string getPassword() const;
	eRole getRole() const;
	void setUsername(std::string username);
	void setNickname(std::string nickname);
	void setPassword(std::string password);
	void setRole(eRole role);

private:
	std::string mUsername;
	std::string mNickname;
	std::string mPassword;
	eRole mRole;
};

#endif
