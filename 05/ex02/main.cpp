#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_signExecShrubberyForm()
{
	std::cout << "\n* test_signExecShrubberyForm *" << std::endl;
	try
	{
		int						grade;
		ShrubberyCreationForm	shrubbery("home");
		std::cout << shrubbery;
		std::cout << ">> Type the grade: ";
		std::cin >> grade;
		Bureaucrat				A("A", grade);

		std::cout << A;
		shrubbery.beSigned(A);
		A.signForm(shrubbery);
		A.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_signExecRobotomyForm()
{
	std::cout << "\n* test_signExecRobotomyForm *" << std::endl;
	try
	{
		int					grade;
		RobotomyRequestForm	robot("housing construction");
		std::cout << robot;
		std::cout << ">> Type the grade: ";
		std::cin >> grade;
		Bureaucrat			B("B", grade);

		std::cout << B;
		robot.beSigned(B);
		B.signForm(robot);
		B.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_signExecPresidentialForm()
{
	std::cout << "\n* test_signExecPresidentialForm *" << std::endl;
	try
	{
		int						grade;
		PresidentialPardonForm	president("PersonX");
		std::cout << president;
		std::cout << ">> Type the grade: ";
		std::cin >> grade;
		Bureaucrat				C("C", grade);

		std::cout << C;
		president.beSigned(C);
		C.signForm(president);
		C.executeForm(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_ng_inConstructor()
{
	std::cout << "\n* test_ng_inConstructor *" << std::endl;
	try
	{
		Bureaucrat	D("D", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	std::srand((unsigned)std::time(NULL));

	test_signExecShrubberyForm();
	test_signExecRobotomyForm();
	test_signExecPresidentialForm();
	// test_ng_inConstructor();
	// system("leaks -q bureaucrat");
	return (0);
}
