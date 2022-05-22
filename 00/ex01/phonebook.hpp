#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include <iostream>
#include <string>
#include <sstream> // std::istringstream

class Contact;

class PhoneBook
{
	private:
		Contact						*contacts[8];
		int							nb_contacts;
		static const std::string	E_NOCONTACT;
		static const std::string	E_INDEX;
		int		stoiNum(std::string &sindex);
	public:
		PhoneBook();
		~PhoneBook();
		static const std::string	E_CMD;
		static const std::string	E_EOF;
		bool	add();
		bool	search();
};

#endif
