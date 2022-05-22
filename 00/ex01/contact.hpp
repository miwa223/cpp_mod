#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
#include <iomanip> // std::setw
#include <string>
#include <cctype> // std::isprint

class Contact
{
	private:
		int							id;
		std::string					first_name;
		std::string					last_name;
		std::string					nickname;
		std::string					phone_number;
		std::string					darkest_secret;
		static const std::string	E_EMPTY;
		static const std::string	E_DIGITS;
		static const std::string	E_PRINTS;
		static const std::string	E_ALNUMS;
		bool	isDigits(std::string &num) const;
		bool	isPrints(std::string &str) const;
		bool	isAlnums(std::string &str) const;
		bool	validateInput(int i, std::string &content) const;
	public:
		Contact();
		~Contact();
		bool	inputContact(int index);
		void	displaySummary();
		void	displayContact();
};

#endif
