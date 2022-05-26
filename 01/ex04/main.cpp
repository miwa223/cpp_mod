#include "File.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid arguments" << std::endl;
		return (1);
	}
	std::string	args[] = {argv[1], argv[2], argv[3]};
	File		file(args);
	file.replace();
	return (0);
}
