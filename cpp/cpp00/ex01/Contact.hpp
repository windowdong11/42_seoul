#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <iomanip>

/*
first name, last name, nickname, phone number, and
darkest secret.
*/

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	static void formatted_print(std::string str)
	{
		if (str.length() > 10)
			std::cout << str.substr(0, 9) << '.';
		else
			std::cout << std::setfill(' ') << std::setw(10) << str;
	}
public:
	Contact() {}
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
		: first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {}
	~Contact() {}
	std::string get_first_name() { return first_name; }
	std::string get_last_name() { return last_name; }
	std::string get_nickname() { return nickname; }
	std::string get_phone_number() { return phone_number; }
	std::string get_darkest_secret() { return darkest_secret; }
	void set_first_name(std::string first_name) { this->first_name = first_name; }
	void set_last_name(std::string last_name) { this->last_name = last_name; }
	void set_nickname(std::string nickname) { this->nickname = nickname; }
	void set_phone_number(std::string phone_number) { this->phone_number = phone_number; }
	void set_darkest_secret(std::string darkest_secret) { this->darkest_secret = darkest_secret; }
	void print_contact()
	{
		formatted_print(first_name);
		std::cout << '|';
		formatted_print(last_name);
		std::cout << '|';
		formatted_print(nickname);
		std::cout << std::endl;
	}
};

#endif