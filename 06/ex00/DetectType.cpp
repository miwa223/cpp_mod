#include "Convert.hpp"

void	Convert::detectType()
{
	if (target.empty())
		throw InvalidArgException();
	if (isInt())
		type = Int;
	else if (isFloat())
		type = Float;
	else if (isDouble())
		type = Double;
	else if (isChar())
		type = Char;
	else
		throw InvalidArgException();
}

bool	Convert::isChar()
{
	if (target.length() == 1)
		return (true);
	return (false);
}

bool	Convert::isInt()
{
	size_t	i = 0;

	if (target[0] == '-' || target[0] == '+')
	{
		i++;
		if (target.length() == 1)
			return (false);
	}
	for (; i < target.length(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(target[i])) == 0)
			return (false);
	}
	return (true);
}

bool	Convert::isFloat()
{
	if (target == "-inff" || target == "+inff" || target== "nanf")
	{
		special_val = true;
		return (true);
	}
	return (isFloatingPointNum(1));
}

bool	Convert::isDouble()
{
	if (target == "-inf" || target == "+inf" || target== "nan")
	{
		special_val = true;
		return (true);
	}
	return (isFloatingPointNum(0));
}

bool	Convert::isFloatingPointNum(const size_t isFloat)
{
	int		i = 0;
	int		i_p = hasValidPoint();
	int		i_e = hasValidEtoEnd(isFloat);

	if (i_p == INVALID || i_e == INVALID)
		return (false);
	if (i_p == NOT_EXIST && i_e == NOT_EXIST)
		return (false);
	if (i_p != NOT_EXIST && i_e != NOT_EXIST && i_e < i_p)
		return (false);
	if (isFloat && !hasFloatSuffix())
		return (false);
	if (target[0] == '-' || target[0] == '+')
		i++;
	return (isValidSyntax(i, i_p, i_e, isFloat));
}

int		Convert::hasValidPoint()
{
	int	i_p = NOT_EXIST;

	for (size_t i = 0; i < target.length(); i++)
	{
		if (target[i] == '.')
		{
			if (i_p == NOT_EXIST)
				i_p = i;
			else
				return (INVALID);
		}
	}
	if (i_p == NOT_EXIST)
		return (NOT_EXIST);
	return (hasNumAroundPoint(i_p));
}

int		Convert::hasNumAroundPoint(int i_p)
{
	if (i_p != 0
		&& std::isdigit(static_cast<unsigned char>(target[i_p - 1])))
		return (i_p);
	if (target[i_p + 1] != '\0'
		&& std::isdigit(static_cast<unsigned char>(target[i_p + 1])))
		return (i_p);
	return (INVALID);
}

int		Convert::hasValidEtoEnd(const size_t isFloat)
{
	int	i_e = hasE();

	if (i_e == INVALID)
		return (INVALID);
	if (i_e == NOT_EXIST)
		return (NOT_EXIST);

	int	res = i_e;
	i_e++;
	if (target[i_e] == '\0')
		return (INVALID);
	if (target[i_e] == '-' || target[i_e] == '+')
		i_e++;
	if (static_cast<size_t>(i_e) == target.length() - isFloat)
		return (INVALID);
	for (; static_cast<size_t>(i_e) < target.length() - isFloat; i_e++)
	{
		if (std::isdigit(static_cast<unsigned char>(target[i_e])) == 0)
			return (INVALID);
	}
	return (res);
}

int		Convert::hasE()
{
	int	i_e = NOT_EXIST;

	for (size_t i = 0; i < target.length(); i++)
	{
		if (target[i] == 'e' || target[i] == 'E')
		{
			if (i_e == NOT_EXIST)
				i_e = i;
			else
				return (INVALID);
		}
	}
	return (i_e);
}

bool	Convert::validBeginToPoint(int i, int i_p)
{
	std::string	beginToPoint = target.substr(i, i_p - i);

	for (size_t j = 0; j < beginToPoint.length(); j++)
	{
		if (std::isdigit(static_cast<unsigned char>(beginToPoint[j])) == 0)
			return (false);
	}
	return (true);
}

bool	Convert::validBeginToE(int i, int i_e)
{
	std::string	beginToE = target.substr(i, i_e - i);

	for (size_t j = 0; j < beginToE.length(); j++)
	{
		if (std::isdigit(static_cast<unsigned char>(beginToE[j])) == 0)
			return (false);
	}
	return (true);
}

bool	Convert::validPointToE(int i_p, int i_e)
{
	std::string	pointToE = target.substr(i_p + 1, i_e - (i_p + 1));

	for (size_t j = 0; j < pointToE.length(); j++)
	{
		if (std::isdigit(static_cast<unsigned char>(pointToE[j])) == 0)
			return (false);
	}
	return (true);
}

bool	Convert::validPointToEnd(int i_p, const size_t isFloat)
{
	std::string	pointToEnd
		= target.substr(i_p + 1, target.length() - (i_p + 1) - isFloat);

	for (size_t j = 0; j < pointToEnd.length(); j++)
	{
		if (std::isdigit(static_cast<unsigned char>(pointToEnd[j])) == 0)
			return (false);
	}
	return (true);
}

bool	Convert::hasFloatSuffix()
{
	if (target[target.length() - 1] == 'f'
		|| target[target.length() - 1] == 'F')
		return (true);
	return (false);
}

bool	Convert::isValidSyntax(int i, int i_p, int i_e, const size_t isFloat)
{
	if (i_p == NOT_EXIST && i_e != NOT_EXIST && validBeginToE(i, i_e))
		return (true);
	if (i_p != NOT_EXIST && i_e == NOT_EXIST
		&& validBeginToPoint(i, i_p) && validPointToEnd(i_p, isFloat))
		return (true);
	if (i_p != NOT_EXIST && i_e != NOT_EXIST
		&& validBeginToPoint(i, i_p) && validPointToE(i_p, i_e))
		return (true);
	return (false);
}
