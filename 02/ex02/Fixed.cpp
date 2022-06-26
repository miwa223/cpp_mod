#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp_num = 0;
}

Fixed::Fixed(const int num)
{
	this->fp_num = (num << fractional_bits);
}

Fixed::Fixed(const float value)
{
	this->fp_num = std::roundf(value * 256);
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed			&Fixed::operator=(const Fixed &fixed)
{
	this->fp_num = fixed.fp_num;
	return (*this);
}

Fixed::~Fixed() {}

bool			Fixed::operator>(const Fixed &fixed) const
{
	return (this->fp_num > fixed.fp_num);
}

bool			Fixed::operator<(const Fixed &fixed) const
{
	return (this->fp_num < fixed.fp_num);
}

bool			Fixed::operator>=(const Fixed &fixed) const
{
	return (this->fp_num >= fixed.fp_num);
}

bool			Fixed::operator<=(const Fixed &fixed) const
{
	return (this->fp_num <= fixed.fp_num);
}

bool			Fixed::operator==(const Fixed &fixed) const
{
	return (this->fp_num == fixed.fp_num);
}

bool			Fixed::operator!=(const Fixed &fixed) const
{
	return !(*this == fixed);
}

Fixed			Fixed::operator+(const Fixed &fixed)
{
	Fixed	res;

	res.fp_num = this->fp_num + fixed.fp_num;
	return (res);
}

Fixed			Fixed::operator-(const Fixed &fixed)
{
	Fixed	res;

	res.fp_num = this->fp_num - fixed.fp_num;
	return (res);
}

Fixed			Fixed::operator*(const Fixed &fixed)
{
	Fixed	res;

	res.fp_num = this->fp_num * fixed.fp_num >> fractional_bits;
	return (res);
}

Fixed			Fixed::operator/(const Fixed &fixed)
{
	Fixed	res;

	res.fp_num = this->fp_num / fixed.fp_num << fractional_bits;
	return (res);
}

Fixed			Fixed::operator--( void )
{
	--this->fp_num;
	return (*this);
}

Fixed			Fixed::operator++( void )
{
	++this->fp_num;
	return (*this);
}

Fixed			Fixed::operator--( int )
{
	Fixed	copy = *this;

	--(*this);
	return (copy);
}

Fixed			Fixed::operator++( int )
{
	Fixed	copy = *this;

	++(*this);
	return (copy);
}

int				Fixed::getRawBits( void ) const
{
	return (this->fp_num);
}

void			Fixed::setRawBits( int const raw )
{
	this->fp_num = raw;
}

float			Fixed::toFloat( void ) const
{
	return ((float)(this->fp_num) / 256);
}

int				Fixed::toInt( void ) const
{
	return (this->fp_num >> fractional_bits);
}

Fixed			&Fixed::min(Fixed &fp1, Fixed &fp2)
{
	if (fp1 < fp2)
		return (fp1);
	return (fp2);
}

const Fixed		&Fixed::min(const Fixed &fp1, const Fixed &fp2)
{
	if (fp1 < fp2)
		return (fp1);
	return (fp2);
}

Fixed			&Fixed::max(Fixed &fp1, Fixed &fp2)
{
	if (fp1 > fp2)
		return (fp1);
	return (fp2);
}

const Fixed		&Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
	if (fp1 > fp2)
		return (fp1);
	return (fp2);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
