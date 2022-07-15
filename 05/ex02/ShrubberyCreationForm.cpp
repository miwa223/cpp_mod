#include <fstream> //ofstream
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137)
{
	this->target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &shrubbery)
	: Form("ShrubberyCreationForm", 145, 137)
{
	*this = shrubbery;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
						const ShrubberyCreationForm &shrubbery)
{
	if (this == &shrubbery)
		return (*this);
	this->target = shrubbery.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeForExec())
		throw Form::GradeTooLowException();

	std::ofstream	writing_file;
	std::string		filename = this->target + "_shrubbery";
	writing_file.open(filename);
	for (int i = 0; i < 2; i++)
	{
		writing_file << "			   \\/ |    |/"      << std::endl
					 << "		  \\/ / \\||/  /_/___/_" << std::endl
					 << "		  \\/   |/ \\/"          << std::endl
					 << "	 _\\__\\_\\   |  /_____/_"   << std::endl
					 << "	       \\  | /          /"   << std::endl
					 << "	__ _-----`  |{,-----------~" << std::endl
					 << "			   \\ }{"            << std::endl
					 << "				}{{"             << std::endl
					 << "				}}{"             << std::endl
					 << "				{{}"             << std::endl
					 << "		, -=-~{ .-^- _"          << std::endl
					 << "	ejm        `}"               << std::endl
					 << "				{"               << std::endl
					 << std::endl;
	}
	writing_file.close();
}
