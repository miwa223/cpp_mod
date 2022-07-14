#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "* TEST 1 *" << std::endl;
		Bureaucrat	A("A", 0);

		A.decrementGrade();
		A.incrementGrade();
		std::cout << A;
	}
	{
		std::cout << "\n* TEST 2 *" << std::endl;
		Bureaucrat	B("B", 150);
		Bureaucrat	C = B;
		Bureaucrat	D("D", 1);
		D = B;

		C.decrementGrade();
		D.incrementGrade();
		std::cout << B << C << D;
	}
	return (0);
}
