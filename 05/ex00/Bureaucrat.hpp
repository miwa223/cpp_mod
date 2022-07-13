#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
		void			GradeTooHighException();
		void			GradeTooLowException();
		std::string		getName();
		int				getGrade();
		void			incrementGrade(int grade);
		void			decrementGrade(int grade);
		// std::iostream	operator<<();
};

#endif
