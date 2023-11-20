#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

void Contact::formatted_print(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setfill(' ') << std::setw(10) << str;
}
Contact::Contact() {}
Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
		: first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {}
Contact::~Contact() {}
std::string Contact::get_first_name() { return first_name; }
std::string Contact::get_last_name() { return last_name; }
std::string Contact::get_nickname() { return nickname; }
std::string Contact::get_phone_number() { return phone_number; }
std::string Contact::get_darkest_secret() { return darkest_secret; }
void Contact::set_first_name(std::string first_name) { this->first_name = first_name; }
void Contact::set_last_name(std::string last_name) { this->last_name = last_name; }
void Contact::set_nickname(std::string nickname) { this->nickname = nickname; }
void Contact::set_phone_number(std::string phone_number) { this->phone_number = phone_number; }
void Contact::set_darkest_secret(std::string darkest_secret) { this->darkest_secret = darkest_secret; }
void Contact::print_contact()
{
	formatted_print(first_name);
	std::cout << '|';
	formatted_print(last_name);
	std::cout << '|';
	formatted_print(nickname);
	std::cout << std::endl;
}
