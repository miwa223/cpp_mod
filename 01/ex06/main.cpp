#include "Harl.hpp"

int	exitError(void)
{
	std::cerr << "Invalid arguments." << std::endl;
	return (1);
}

int	stoiLevel(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}

void	harlFilter(Harl harl, int level)
{
	enum	e_levels
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	switch (level)
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (exitError());

	std::string	level = argv[1];
	Harl		harl;

	harlFilter(harl, stoiLevel(level));
	return (0);
}
