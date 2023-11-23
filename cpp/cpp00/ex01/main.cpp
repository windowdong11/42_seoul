#include <iostream>
#include <string>
#include "PhoneBook.hpp"

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
			if (!phone_book.add_contact())
			{
				std::cout << std::endl;
				std::cout << "Failed to add contact.";
				break;
			}
		}
		else if (command == "SEARCH")
		{
			if (!phone_book.search())
			{
				std::cout << std::endl;
				std::cout << "Failed to search contact.";
				break;
			}
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Wrong command. Please enter again." << std::endl;
		}
		std::cout << std::endl;
	}
	if (std::cin.eof())
		std::cout << std::endl << "Found EOF! Bye!" << std::endl;
	return (0);
}