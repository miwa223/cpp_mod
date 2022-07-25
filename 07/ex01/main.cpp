#include "iter.hpp"

int		main()
{
	test_string();
	test_double();
	test_instantiated_function_template();
	return (0);
}

void	test_string()
{
	std::cout << "> test_string\n";
	std::string	array[3] = {"a", "b", "c"};
	size_t		len = 3;

	for (size_t i = 0; i < len; i++)
		std::cout << array[i];
	std::cout << std::endl;

	iter(array, len, func_string);

	for (size_t i = 0; i < len; i++)
		std::cout << array[i];
	std::cout << std::endl;
}

void	test_double()
{
	std::cout << "> test_double\n";
	double	array[2] = {0.1, 1.1};
	int		len = 2;

	for (int i = 0; i < len; i++)
		std::cout << array[i] << "  ";
	std::cout << std::endl;

	iter(array, len, func_double);

	for (int i = 0; i < len; i++)
		std::cout << array[i] << "  ";
	std::cout << std::endl;
}

void	test_instantiated_function_template()
{
	std::cout << "> test_instantiated_function_template\n";
	int	array[2] = {0, 1};
	int	len = 2;

	for (int i = 0; i < len; i++)
		std::cout << array[i] << "  ";
	std::cout << std::endl;

	iter(array, len, func_template<int>);

	for (int i = 0; i < len; i++)
		std::cout << array[i] << "  ";
	std::cout << std::endl;
}

void	func_string(std::string &ele)
{
	ele += "-";
}

int		func_double(double &ele)
{
	ele += 0.1;
	return (0);
}
