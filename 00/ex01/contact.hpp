#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
#include <iomanip> // std::setw
#include <string>
#include <cctype> // std::isprint

#define E_DIGITS "Only Digits acceptable. Try again."
#define E_PRINTS "Only printable characters acceptable. Try again."

class Contact
{
	private:
		int			id;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();
		void	inputContact(int index);
		bool	isDigits(std::string &num);
		bool	isPrints(std::string &str);
		bool	isValidIndex(int index);
		void	displaySummary();
		void	displayContact();
};

#endif
