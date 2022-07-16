#include "Bureaucrat.hpp"
#include "Form.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < HIGHEST_GRADE)
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
	return (HIGHEST_GRADE);
}

int				Bureaucrat::getLowestGrade()
{
	return (LOWEST_GRADE);
}

void			Bureaucrat::incrementGrade()
{
	this->grade--;
	if (this->grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

void			Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

void			Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed "
			<< form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign "
			<< form.getName() << " because " << e.what() << "." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream& stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << "." << std::endl;
	return (stream);
}
