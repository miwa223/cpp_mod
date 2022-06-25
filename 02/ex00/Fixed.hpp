#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:
		int					fp_num;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
