#include "File.hpp"

File::File(std::string args[])
{
	name_ = args[0];
	name_new_ = name_ + ".replace";
	s_original_ = args[1];
	s_new_ = args[2];
}

File::~File() {}

bool	File::isValidArg()
{
	if (!s_original_.empty())
		return (true);
	else
	{
		std::cerr << "Invalid arguments" << std::endl;
		return (false);
	}
}

bool	File::isValidIn(std::ifstream &ifs)
{
	if (ifs)
		return (true);
	else
	{
		std::cerr << name_ << ": " << std::strerror(errno) << std::endl;
		return (false);
	}
}

bool	File::isValidOut(std::ofstream &ofs)
{
	if (ofs)
		return (true);
	else
	{
		std::cerr << name_new_ << ": " << std::strerror(errno) << std::endl;
		return (false);
	}
}

std::string	File::replaceLine(std::string line)
{
	size_t					begin = 0;
	std::string::size_type	i;

	while ((i = line.find(s_original_, begin)) != std::string::npos)
	{
		line.erase(i, s_original_.length());
		line.insert(i, s_new_);
		begin = i + s_new_.length();
	}
	return (line);
}

void	File::replace()
{
	if (!isValidArg())
		return ;

	std::ifstream	foriginal(name_);
	if (!isValidIn(foriginal))
		return ;
	std::ofstream	fnew(name_new_);
	if (!isValidOut(fnew))
		return ;

	std::string		line;
	while (std::getline(foriginal, line))
	{
		if (foriginal.eof())
			line = replaceLine(line);
		else
			line = replaceLine(line + "\n");
		fnew << line;
	}
}
