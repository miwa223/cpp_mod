#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include <iostream>
#include <string>
#include <sstream> // std::istringstream

#define E_CMD "Invaild command."
#define E_NOCONTACT "No contact found. Add a contact first."
#define E_INDEX "Index not found. Try again."

class Contact;

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add(int index);
		void	search();
		int		stoiNum(std::string &sindex);
	private:
		Contact	*contacts[8];
};

#endif
