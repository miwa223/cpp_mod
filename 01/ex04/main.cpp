#include "File.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid arguments" << std::endl;
		return (1);
	}

	File	file(argv);
	file.replace();
	return (0);
}
