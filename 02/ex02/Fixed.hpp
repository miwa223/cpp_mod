#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <cstdbool>

class Fixed
{
	private:
		int					fp_num;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float value);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);

		Fixed operator--( void );
		Fixed operator++( void );
		Fixed operator--( int );
		Fixed operator++( int );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed &min(Fixed &fp1, Fixed &fp2);
		static const Fixed &min(const Fixed &fp1, const Fixed &fp2);
		static Fixed &max(Fixed &fp1, Fixed &fp2);
		static const Fixed &max(const Fixed &fp1, const Fixed &fp2);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);

#endif
