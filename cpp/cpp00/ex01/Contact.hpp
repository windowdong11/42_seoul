#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <iomanip>

/*
Contact contains first name, last name, nickname, phone number, darkest secret.
*/
class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	static void formatted_print(std::string str);
public:
	Contact();
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
	~Contact();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	void set_phone_number(std::string phone_number);
	void set_darkest_secret(std::string darkest_secret);
	void print();
	void print_all();
};

#endif