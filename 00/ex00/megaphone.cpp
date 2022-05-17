#include <iostream>
#include <string>

int	main(int argc, char *argv[]) {
	std::string	s;
	int			i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			if (islower(argv[i][j]))
				s += (argv[i][j] - 32);
			else
				s += argv[i][j];
		}
		i++;
	}
	std::cout << s << std::endl;
	return (0);
}
