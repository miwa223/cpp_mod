#include "Form.hpp"
#include "Bureaucrat.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade too low");
}

const char	*Form::NotSignedException::what() const throw()
{
	return ("Form: signature required");
}

void		Form::assertion() const
{
	if (grade_for_sign < Bureaucrat::getHighestGrade()
		|| grade_for_sign < Bureaucrat::getHighestGrade())
		throw Form::GradeTooHighException();
	else if (grade_for_sign > Bureaucrat::getLowestGrade()
		|| grade_for_exec > Bureaucrat::getLowestGrade())
		throw Form::GradeTooLowException();
}

Form::Form()
	: name(""), is_signed(false), grade_for_sign(100), grade_for_exec(50)
{
	assertion();
}

Form::Form(std::string name, int grade_for_sign, int grade_for_exec)
	: name(name), is_signed(false), grade_for_sign(grade_for_sign), grade_for_exec(grade_for_exec)
{
	assertion();
}

Form::Form(const Form &form)
	: name(form.name), grade_for_sign(form.grade_for_sign), grade_for_exec(form.grade_for_exec)
{
	*this = form;
}

Form	&Form::operator=(const Form &form)
{
	if (this == &form)
		return (*this);
	this->is_signed = form.is_signed;
	return (*this);
}

Form::~Form() {}

std::string		Form::getName() const
{
	return (this->name);
}

bool			Form::getIsSigned() const
{
	return (this->is_signed);
}

int				Form::getGradeForSign() const
{
	return (this->grade_for_sign);
}

int				Form::getGradeForExec() const
{
	return (this->grade_for_exec);
}

void			Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->grade_for_sign)
		this->is_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream& stream, const Form &form)
{
	std::string	res = "No";

	if (form.getIsSigned())
		res = "Yes";
	stream << "[Form info]"
		<< "\nName: " << form.getName()
		<< "\nGrade required for signature: " << form.getGradeForSign()
		<< "\nGrade required for execution: " << form.getGradeForExec()
		<< "\nSinged: " << res
		<< std::endl;
	return (stream);
}
