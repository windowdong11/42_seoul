#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

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
		int next_index;
		int capacity;
		void print_contact(int index);
		void print_contact_list();
	public:
		PhoneBook();
		~PhoneBook();
		bool add_contact();
		bool search();
};

#endif