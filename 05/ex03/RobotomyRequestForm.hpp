#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &robot);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &robot);
		virtual ~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const &executor) const;
		virtual Form	*makeSpecificForm(std::string target) const;
};

#endif
