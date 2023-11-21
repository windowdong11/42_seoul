#include "PhoneBook.hpp"

/*
• PhoneBook
◦ It has an array of contacts.
◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
replace the oldest one by the new one.
◦ Please note that dynamic allocation is forbidden.
*/
PhoneBook::PhoneBook() : count(0) {}
PhoneBook::~PhoneBook() {}
void PhoneBook::add_contact(Contact contact)
{
	if (count == 8)
		count = 0;
	this->contact[count] = contact;
	count++;
}

void PhoneBook::print_contact(int index)
{
	if (index < 0 || index >= count)
	{
		std::cout << "There is no contact." << std::endl;
		return;
	}
	std::cout << "  index   |first name|last name | nickname " << std::endl;
	contact[index].print_contact();
}

void PhoneBook::print_contact_list()
{
	std::cout << "  index   |first name|last name | nickname " << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setfill(' ') << std::setw(10) << i << '|';
		contact[i].print_contact();
	}
}