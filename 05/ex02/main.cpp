#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_signExecShrubberyForm()
{
	std::cout << "\n* test_signExecShrubberyForm *" << std::endl;
	try
	{
		int	grade;

		Form *formA = new ShrubberyCreationForm("home");
		std::cout << *formA;
		std::cout << ">> Type the grade: ";
		std::cin >> grade;
		Bureaucrat	A("A", grade);

		std::cout << A;
		formA->beSigned(A);
		A.signForm(*formA);
		A.executeForm(*formA);
		delete formA;
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
		int	grade;
		Form *formB = new RobotomyRequestForm("housing construction");
		std::cout << *formB;
		std::cout << ">> Type the grade: ";
		std::cin >> grade;
		Bureaucrat	B("B", grade);

		std::cout << B;
		formB->beSigned(B);
		B.signForm(*formB);
		B.executeForm(*formB);
		std::cout << *formB;
		delete formB;
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
		int	grade;
		Form *formC = new PresidentialPardonForm("PersonX");
		std::cout << *formC;
		std::cout << ">> Type the grade: ";
		std::cin >> grade;
		Bureaucrat	C("C", grade);

		std::cout << C;
		formC->beSigned(C);
		C.signForm(*formC);
		C.executeForm(*formC);
		delete formC;
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
	test_signExecShrubberyForm();
	test_signExecRobotomyForm();
	test_signExecPresidentialForm();
	// test_ng_inConstructor();
	return (0);
}
