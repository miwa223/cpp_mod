#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "* TEST 1: constructor *" << std::endl;
		try
		{
			Bureaucrat	A("A", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n* TEST 2: increment *" << std::endl;
		try
		{
			Bureaucrat	B("B", 1);

			std::cout << B;
			B.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n* TEST 3: decrement *" << std::endl;
		try
		{
			Bureaucrat	B("B", 150);

			std::cout << B;
			B.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n* TEST 4: success *" << std::endl;
		try
		{
			Bureaucrat	D("D", 100);

			D.incrementGrade();
			std::cout << D;
			D.decrementGrade();
			std::cout << D;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
