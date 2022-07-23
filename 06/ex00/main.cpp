#include "Convert.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid argument" << std::endl;
		return (0);
	}
	Convert	arg(argv[1]);
	try
	{
		arg.convertor();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		arg.displayFailureResults();
	}
	return (0);
}
