#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		std::cout << "* TEST 1: fail in constructor *" << std::endl;
		try
		{
			Form	FormA("formA", 200, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n* TEST 2: successfully sign the form *" << std::endl;
		try
		{
			Bureaucrat	B("B", 99);
			Form		formB("formB", 100, 50);

			std::cout << B;
			formB.beSigned(B);
			std::cout << formB;
			B.signForm(formB);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n* TEST 3: fail to sign the form, need a higher grade *" << std::endl;
		try
		{
			Bureaucrat	C("C", 101);
			Form		formC("formC", 100, 50);

			std::cout << C;
			C.decrementGrade();
			std::cout << formC;
			C.signForm(formC);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
