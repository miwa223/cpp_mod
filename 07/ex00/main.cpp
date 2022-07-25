#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;

	/*
	std::cout << "\n> test: double" << std::endl;
	double e = 0.1;
	double f = 0.2;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;

	std::cout << "\n> test: the same values" << std::endl;
	int g = 2;
	int h = 2;
	int &ans = ::max( g, h );
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
	std::cout << "g  :"<< &g << std::endl;
	std::cout << "h  :"<< &h << std::endl;
	std::cout << "ans:"<< &ans << std::endl;
	*/
	return 0;
}
