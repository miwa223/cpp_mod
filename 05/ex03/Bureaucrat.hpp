#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
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

		const std::string	name;
		int					grade;
		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		static int	getHighestGrade();
		static int	getLowestGrade();
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &form);
		void		executeForm(Form const &form);
};

std::ostream	&operator<<(std::ostream& stream, const Bureaucrat &bureaucrat);

#endif
