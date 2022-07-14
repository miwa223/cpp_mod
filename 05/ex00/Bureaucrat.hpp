#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
};

std::ostream	&operator<<(std::ostream& stream, const Bureaucrat &bureaucrat);

#endif
