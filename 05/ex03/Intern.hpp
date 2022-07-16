#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class Form;

class Intern
{
	public:
		Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		~Intern();

		Form	*makeForm(std::string formname, std::string target);
};

#endif
