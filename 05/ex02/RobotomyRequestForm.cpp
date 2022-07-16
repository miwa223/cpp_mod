#include <cstdlib> //srand, rand
#include <ctime> //time
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("robotomy request", 72, 45)
{
	this->target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("robotomy request", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robot)
	: Form("robotomy request", 72, 45)
{
	*this = robot;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
						const RobotomyRequestForm &robot)
{
	if (this == &robot)
		return (*this);
	this->target = robot.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeForExec())
		throw Form::GradeTooLowException();
	std::cout << "bzz-bzz..." << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << this->target
			<< " has been successfully robotomized!" << std::endl;
	}
	else
		std::cout << "Failed to robotomize " << this->target << std::endl;
}
