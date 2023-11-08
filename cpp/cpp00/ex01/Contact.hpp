#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact(std::string firstname,
					std::string lastname,
					std::string nickname,
					std::string phone_number,
					std::string darkest_secret);
	~Contact();
};

Contact::Contact(std::string firstname,
								 std::string lastname,
								 std::string nickname,
								 std::string phone_number,
								 std::string darkest_secret)
{
}

Contact::~Contact()
{
}

#endif