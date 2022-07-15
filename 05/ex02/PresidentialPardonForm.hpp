#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &president);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &president);
		virtual ~PresidentialPardonForm();

		virtual void	execute(Bureaucrat const &executor) const;
};

#endif
