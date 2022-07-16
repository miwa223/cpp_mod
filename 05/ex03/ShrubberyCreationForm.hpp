#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubbery);
		virtual ~ShrubberyCreationForm();

		virtual void	execute(Bureaucrat const &executor) const;
		virtual Form	*makeSpecificForm(std::string target) const;
};

#endif
