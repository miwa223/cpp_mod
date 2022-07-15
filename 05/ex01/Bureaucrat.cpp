#include "Bureaucrat.hpp"
#include "Form.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: grade too low");
}

Bureaucrat::Bureaucrat() : name(""), grade(LOWEST_GRADE)
{
	if (this->grade < HIGHTEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	if (grade < HIGHTEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
	*this = bureaucrat;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	this->grade = bureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string		Bureaucrat::getName() const
{
	return (this->name);
}

int				Bureaucrat::getGrade() const
{
	return (this->grade);
}

int				Bureaucrat::getHighestGrade()
{
	return (HIGHTEST_GRADE);
}

int				Bureaucrat::getLowestGrade()
{
	return (LOWEST_GRADE);
}

void			Bureaucrat::incrementGrade()
{
	this->grade--;
	if (this->grade == HIGHTEST_GRADE - 1)
		throw Bureaucrat::GradeTooHighException();
}

void			Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade == LOWEST_GRADE + 1)
		throw Bureaucrat::GradeTooLowException();
}

void			Bureaucrat::signForm(const Form &form)
{
	if (form.getIsSigned())
		std::cout << this->name << " signed "
			<< form.getName() << "." << std::endl;
	else
		std::cout << this->name << " couldn't sign "
			<< form.getName() << " because of the low grade." << std::endl;
}

std::ostream	&operator<<(std::ostream& stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << "." << std::endl;
	return (stream);
}
