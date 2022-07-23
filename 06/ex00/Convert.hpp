#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>
#include <iomanip>
#include <cstdlib>
#include <cctype> //isprint

enum Type
{
	Char,
	Int,
	Float,
	Double,
	Default
};

class Convert
{
	private:
		class InvalidArgException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Type 		type;
		std::string	target;
		char		c;
		int			i_num;
		float		f_num;
		double		d_num;
		bool		special_val;
		bool		i_erange;
		bool		f_erange;

		static const int	NOT_EXIST = -1;
		static const int	INVALID = -2;

		void	detectType();
		bool	isChar();
		bool	isInt();
		bool	isFloat();
		bool	isDouble();
		bool	isFloatingPointNum(const size_t isFloat);
		int		hasValidPoint();
		int		hasNumAroundPoint(int i_p);
		int		hasValidEtoEnd(const size_t isFloat);
		int		hasE();
		bool	validBeginToPoint(int i, int i_p);
		bool	validBeginToE(int i, int i_e);
		bool	validPointToE(int i_p, int i_e);
		bool	validPointToEnd(int i_p, const size_t isFloat);
		bool	hasFloatSuffix();
		bool	isValidSyntax(int i, int i_p, int i_e, const size_t isFloat);

		void	strToOtherTypes();
		void	strToChar();
		void	strToInt();
		void	strToFloat();
		void	strToDouble();

		void	charToOtherTypes();
		void	intToOtherTypes();
		void	floatToOtherTypes();
		void	doubleToOtherTypes();

		bool	isCharRange(double num);
		bool	isIntRange(double num);
		bool	isFloatRange(double num);

		void	displayResults();
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();

	public:
		Convert(std::string target = "");
		Convert(const Convert &convert);
		Convert &operator=(const Convert &convert);
		~Convert();
		void	convertor();
		void	displayFailureResults();
};

#endif
