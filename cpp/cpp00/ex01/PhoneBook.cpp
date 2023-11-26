#include "PhoneBook.hpp"

/*
• PhoneBook
◦ It has an array of contacts.
◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
replace the oldest one by the new one.
◦ Please note that dynamic allocation is forbidden.
*/
PhoneBook::PhoneBook() : next_index(0), capacity(0) {}
PhoneBook::~PhoneBook() {}
bool PhoneBook::add_contact()
{
	std::cout << "[ADD] Input new contact information" << std::endl;
	std::string first_name;
	std::cout << "first name: ";
	while (std::getline(std::cin, first_name) && !first_name.length())
	{
		std::cout << "field cannot be empty!" << std::endl;
		std::cout << "first name: ";
	}
	if (std::cin.eof())
		return false;

	std::string last_name;
	std::cout << "last name: ";
	while (std::getline(std::cin, last_name) && !last_name.length())
	{
		std::cout << "field cannot be empty!" << std::endl;
		std::cout << "last name: ";
	}
	if (std::cin.eof())
		return false;

	std::string nickname;
	std::cout << "nickname: ";
	while (std::getline(std::cin, nickname) && !nickname.length())
	{
		std::cout << "field cannot be empty!" << std::endl;
		std::cout << "nickname : ";
	}
	if (std::cin.eof())
		return false;

	std::string phone_number;
	std::cout << "phone number: ";
	while (std::getline(std::cin, phone_number) && !phone_number.length())
	{
		std::cout << "field cannot be empty!" << std::endl;
		std::cout << "phone number : ";
	}
	if (std::cin.eof())
		return false;

	std::string darkest_secret;
	std::cout << "darkest secret: ";
	while (std::getline(std::cin, darkest_secret) && !darkest_secret.length())
	{
		std::cout << "field cannot be empty!" << std::endl;
		std::cout << "darkest secret : ";
	}
	if (std::cin.eof())
		return false;
	if (next_index == 8)
		next_index = 0;
	this->contact[next_index] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	next_index++;
	if (capacity != 8)
		capacity++;
	return true;
}

bool PhoneBook::search()
{
	std::cout << "[SEARCH]" << std::endl;
	print_contact_list();
	std::cout << "Enter an index of contact : ";
	std::string index;
	while (getline(std::cin, index) && (index.length() != 1 || index[0] < '0' || index[0] > '7'))
	{
		std::cout << "Wrong index. Please enter again." << std::endl;
		std::cout << "Enter an index of contact : ";
	}
	if (std::cin.eof())
		return false;
	print_contact(index[0] - '0');
	return true;
}

void PhoneBook::print_contact(int index)
{
	if (index < 0 || index >= next_index)
	{
		std::cout << "There is no contact." << std::endl;
		return;
	}
	contact[index].print_all();
}

void PhoneBook::print_contact_list()
{
	std::cout << std::setfill(' ') << std::setw(10) << std::left << "index" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << std::left << "first name" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << std::left << "last name" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << std::left << "nickname" << std::endl;
	for (int i = 0; i < capacity; i++)
	{
		std::cout << std::setfill(' ') << std::setw(10) << i << '|';
		contact[i].print();
	}
}