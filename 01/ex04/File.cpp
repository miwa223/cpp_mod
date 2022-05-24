#include "File.hpp"

File::File(char *argv[])
{
	name_ = argv[1];
	name_new_ = name_ + ".replace";
	s_original_ = argv[2];
	s_new_ = argv[3];
}

File::~File() {}

std::string	File::replaceLine(std::string line)
{
	std::string				replaced = "";
	size_t					begin = 0;
	std::string::size_type	i = line.find(s_original_);

	if (i == std::string::npos)
		return (line);
	while (i != std::string::npos)
	{
		replaced += (line.substr(begin, i - begin) + s_new_);
		begin = i + s_original_.length();
		i = line.find(s_original_, i + s_original_.length());
	}
	replaced += line.substr(begin);
	return (replaced);
}

bool	File::isValidIn(std::ifstream &ifs)
{
	if (ifs)
		return (true);
	else
	{
		std::cerr << name_ << ": " << strerror(errno) << std::endl;
		return (false);
	}
}

bool	File::isValidOut(std::ofstream &ofs)
{
	if (ofs)
		return (true);
	else
	{
		std::cerr << name_new_ << ": " << strerror(errno) << std::endl;
		return (false);
	}
}

bool	File::isValidArg()
{
	if (s_original_.length() > 0)
		return (true);
	else
	{
		std::cerr << "Invalid arguments" << std::endl;
		return (false);
	}
}

void	File::replace()
{
	if (!isValidArg())
		return ;

	std::ifstream	foriginal(name_);
	std::ofstream	fnew(name_new_);
	if (!isValidIn(foriginal))
		return ;
	if (!isValidOut(fnew))
		return ;

	std::string		line;
	while (std::getline(foriginal, line))
	{
		if (!isValidIn(foriginal))
			return ;
		if (line.length() == 0)
			line += "\n";
		line = replaceLine(line);
		if (foriginal.eof())
			fnew << line;
		else
			fnew << line << std::endl;
	}
}
