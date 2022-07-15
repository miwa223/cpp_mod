#include "Bureaucrat.hpp"

const char	*GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char	*GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

Bureaucrat::Bureaucrat() : name(""), grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << this->name << ": Bureaucrat constructor" << std::endl;
	this->grade = grade;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
	std::cout<< this->name << ": Bureaucrat copy constructor" << std::endl;
	*this = bureaucrat;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	std::cout << this->name << ": Bureaucrat copy assignment operator" << std::endl;
	this->grade = bureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << ": Bureaucrat destructor" << std::endl;
}

std::string		Bureaucrat::getName() const
{
	return (this->name);
}

int				Bureaucrat::getGrade() const
{
	return (this->grade);
}

void			Bureaucrat::incrementGrade()
{
	this->grade--;
	if (this->grade == 0)
		throw GradeTooHighException();
}

void			Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade == 151)
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream& stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << "." << std::endl;
	return (stream);
}
