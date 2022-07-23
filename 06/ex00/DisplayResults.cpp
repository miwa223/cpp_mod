#include <cmath> //modf, abs
#include "Convert.hpp"

void	Convert::displayResults()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void	Convert::printChar()
{
	if (special_val)
		std::cout << "char: " << "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	Convert::printInt()
{
	if (special_val || i_erange)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << i_num << std::endl;
}

void	Convert::printFloat()
{
	float	int_part = 0.0;
	float	fractional_part;

	std::cout << "float: ";
	if (f_erange)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << f_num;
	if (!special_val)
	{
		fractional_part = std::modf(f_num, &int_part);
		if (std::abs(f_num) < 1000000
			&& !(std::abs(int_part) < 100000 && fractional_part != 0))
			std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void	Convert::printDouble()
{
	double	int_part = 0.0;
	double	fractional_part;

	std::cout << "double: " << d_num;
	if (!special_val)
	{
		fractional_part = std::modf(d_num, &int_part);
		if (std::abs(d_num) < 1000000
			&& !(std::abs(int_part) < 100000 && fractional_part != 0))
			std::cout << ".0";
	}
	std::cout << std::endl;
}

void	Convert::displayFailureResults()
{
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: impossible" << std::endl
		<< "double: impossible" << std::endl;
}
