#include "Convert.hpp"

void	Convert::strToOtherTypes()
{
	switch (type)
	{
		case Char:
			strToChar();
			charToOtherTypes();
			break;
		case Int:
			strToInt();
			intToOtherTypes();
			break;
		case Float:
			strToFloat();
			floatToOtherTypes();
			break;
		case Double:
			strToDouble();
			doubleToOtherTypes();
			break;
		case Default:
			throw InvalidArgException();
	}
}

void	Convert::strToChar()
{
	if (!std::isprint(target.c_str()[0]))
		throw InvalidArgException();
	c = target.c_str()[0];
}

void	Convert::strToInt()
{
	long tmp = std::strtol(target.c_str(), NULL, 10);

	if (errno == ERANGE || !isIntRange(tmp))
		throw InvalidArgException();
	i_num = static_cast<int>(tmp);
}

void	Convert::strToFloat()
{
	double tmp = std::strtod(target.c_str(), NULL);

	if (errno == ERANGE || (!special_val && !isFloatRange(tmp)))
		throw InvalidArgException();
	f_num = static_cast<float>(tmp);
}

void	Convert::strToDouble()
{
	d_num = std::strtod(target.c_str(), NULL);

	if (errno == ERANGE)
		throw InvalidArgException();
}

void	Convert::charToOtherTypes()
{
	i_num = static_cast<int>(c);
	f_num = static_cast<float>(c);
	d_num = static_cast<double>(c);
}

void	Convert::intToOtherTypes()
{
	if (isCharRange(i_num))
		c = static_cast<char>(i_num);
	f_num = static_cast<float>(i_num);
	d_num = static_cast<double>(i_num);
}

void	Convert::floatToOtherTypes()
{
	if (isCharRange(f_num))
		c = static_cast<char>(f_num);
	if (isIntRange(f_num))
		i_num = static_cast<int>(f_num);
	else
		i_erange = true;
	d_num = static_cast<double>(f_num);
}

void	Convert::doubleToOtherTypes()
{
	if (isCharRange(d_num))
		c = static_cast<char>(d_num);
	if (isIntRange(d_num))
		i_num = static_cast<int>(d_num);
	else
		i_erange = true;
	if (isFloatRange(d_num) || special_val)
		f_num = static_cast<float>(d_num);
	else
		f_erange = true;
}

bool	Convert::isCharRange(double num)
{
	if (std::numeric_limits<char>::min() <= num
		&& num <= std::numeric_limits<char>::max())
		return (true);
	return (false);
}

bool	Convert::isIntRange(double num)
{
	if (std::numeric_limits<int>::min() <= num
		&& num <= std::numeric_limits<int>::max())
		return (true);
	return (false);
}

bool	Convert::isFloatRange(double num)
{
	if (std::numeric_limits<float>::lowest() <= num
		&& num <= std::numeric_limits<float>::max())
		return (true);
	return (false);
}
