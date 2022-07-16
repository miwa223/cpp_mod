#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	return (*this);
}

Intern::~Intern() {}

Form	*Intern::makeForm(std::string formname, std::string target)
{
	ShrubberyCreationForm	shrubbery(target);
	RobotomyRequestForm		robotomy(target);
	PresidentialPardonForm	president(target);

	Form	*forms[3] = {&shrubbery, &robotomy, &president};
	for (size_t i = 0; i < 3; i++)
	{
		if (formname == forms[i]->getName())
		{
			std::cout << "Intern creates " << formname << std::endl;
			return (forms[i]->makeSpecificForm(target));
		}
	}
	std::cerr << "Intern: Specified form doesn't exist." << std::endl;
	return (NULL);
}
