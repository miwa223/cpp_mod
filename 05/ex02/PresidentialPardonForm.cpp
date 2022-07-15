#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", 25, 5)
{
	this->target = "";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &president)
	: Form("PresidentialPardonForm", 25, 5)
{
	*this = president;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
						const PresidentialPardonForm &president)
{
	if (this == &president)
		return (*this);
	this->target = president.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeForExec())
		throw Form::GradeTooLowException();
	std::cout << this->target
		<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
