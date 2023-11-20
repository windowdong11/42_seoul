#include <iostream>
#include <string>
#include "PhoneBook.hpp"

Contact command_add()
{
	std::cout << "first name: ";
	std::string first_name;
	std::getline(std::cin, first_name);
	if (std::cin.eof())
		return Contact();

	std::cout << "last name: ";
	std::string last_name;
	std::getline(std::cin, last_name);
	if (std::cin.eof())
		return Contact();

	std::cout << "nickname: ";
	std::string nickname;
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		return Contact();

	std::cout << "phone number: ";
	std::string phone_number;
	std::getline(std::cin, phone_number);
	if (std::cin.eof())
		return Contact();

	std::cout << "darkest secret: ";
	std::string darkest_secret;
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof())
		return Contact();
	return Contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

int main()
{
	PhoneBook phone_book;

	while (1)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Please enter a command: ";
		std::string command;
		if (!getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			Contact new_contact = command_add();
			if (std::cin.eof())
				break;
			phone_book.add_contact(new_contact);
		}
		else if (command == "SEARCH")
		{
			phone_book.print_contact_list();
			std::cout << "Enter an index of contact : ";
			std::string index;
			while (getline(std::cin, index) && (index.length() != 1 || index[0] < '0' || index[0] > '7'))
			{
				std::cout << "Wrong index. Please enter again." << std::endl;
				std::cout << "Enter an index of contact : ";
			}
			if (std::cin.eof())
				break;
			phone_book.print_contact(index[0] - '0');
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Wrong command. Please enter again." << std::endl;
		}
	}
	if (std::cin.eof())
		std::cout << std::endl << "Found EOF! Bye!" << std::endl;
	return (0);
}