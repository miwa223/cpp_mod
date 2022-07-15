#ifndef FORM_HPP
#define FORM_HPP

#include <cstdbool>
#include <string>
#include <iostream>

class Bureaucrat;

class Form
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
		bool				is_signed;
		const int			grade_for_sign;
		const int			grade_for_exec;

	public:
		Form();
		Form(std::string name, int grade_for_sign, int grade_for_exec);
		Form(const Form &form);
		Form &operator=(const Form &form);
		~Form();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeForSign() const;
		int			getGradeForExec() const;
		void		beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream& stream, const Form &form);

#endif
