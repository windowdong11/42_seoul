#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

/* 
• PhoneBook
◦ It has an array of contacts.
◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
replace the oldest one by the new one.
◦ Please note that dynamic allocation is forbidden.
*/

class PhoneBook {
	private:
		Contact contact[8];
		int count;
	public:
		PhoneBook() : count(0) {}
		~PhoneBook() {}
		void add_contact(Contact contact)
		{
			if (count == 8)
				count = 0;
			this->contact[count] = contact;
			count++;
		}
		void print_contact(int index)
		{
			if (index < 0 || index >= count)
			{
				std::cout << "There is no contact." << std::endl;
				return;
			}
			contact[index].print_contact();
		}
		void print_contact_list()
		{
			std::cout << "  index   |first name|last name | nickname " << std::endl;
			for (int i = 0; i < count; i++)
			{
				std::cout << std::setfill(' ') << std::setw(10) << i << '|';
				print_contact(i);
			}
		}
};

#endif