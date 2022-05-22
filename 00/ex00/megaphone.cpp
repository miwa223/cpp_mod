#include <iostream>
#include <string>
#include <ctype.h>

int	main(int argc, char *argv[]) {
	std::string	res;
	std::string	str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			res += static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
	}
	std::cout << res << std::endl;
	return (0);
}
