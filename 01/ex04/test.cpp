#include "File.hpp"

int	main(void)
{
	Test_replace();
	return (0);
}

// prerequisite: edit a file <filename>.expected as expected.
void	Test_replace()
{
	compareFile("testfiles/normal", "hello", "11");
	compareFile("testfiles/no_newline", "12", "XY");
	compareFile("testfiles/empty", " ", "X");
}

void	compareFile(std::string filename, std::string s1, std::string s2)
{
	std::string		args[] = {filename, s1, s2};
	File			testfile(args);
	testfile.replace();

	std::ifstream	f_replace(args[0] + ".replace");
	if (!isValidIn(f_replace, args[0] + ".replace"))
		return ;
	std::ifstream	f_exp(args[0] + ".expected");
	if (!isValidIn(f_exp, args[0] + ".expected"))
		return ;
	std::string		actual;
	std::string		expected;
	while (std::getline(f_replace, actual) && std::getline(f_exp, expected))
	{
		if (actual != expected)
		{
			std::cerr << "+" << actual << std::endl;
			std::cerr << "-" << expected << std::endl;
		}
	}
}

bool	isValidIn(std::ifstream &ifs, std::string filename)
{
	if (ifs)
		return (true);
	else
	{
		std::cerr << "[TEST]" << filename << ": " << strerror(errno) << std::endl;
		return (false);
	}
}
