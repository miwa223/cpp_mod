#include "Convert.hpp"

const char	*Convert::InvalidArgException::what() const throw()
{
	return ("Error: Invalid argument");
}

Convert::Convert(std::string target)
{
	this->type = Default;
	this->target = target;
	this->c = '\0';
	this->i_num = 0;
	this->f_num = 0.0f;
	this->d_num = 0.0;
	this->special_val = false;
	this->i_erange = false;
	this->f_erange = false;
}

Convert::Convert(const Convert &convert)
{
	*this = convert;
}

Convert	&Convert::operator=(const Convert &convert)
{
	if (this == &convert)
		return (*this);
	this->type = convert.type;
	this->target = convert.target;
	this->c = convert.c;
	this->i_num = convert.i_num;
	this->f_num = convert.f_num;
	this->d_num = convert.d_num;
	this->special_val = convert.special_val;
	this->i_erange = convert.i_erange;
	this->f_erange = convert.f_erange;
	return (*this);
}

Convert::~Convert() {}

void	Convert::convertor()
{
	detectType();
	strToOtherTypes();
	displayResults();
}
