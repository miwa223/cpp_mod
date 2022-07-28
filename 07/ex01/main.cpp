#include "iter.hpp"

template <class T> void	func_template(T const &ele)
{
	std::cout << ele << " ";
}

void	func_string(std::string const &ele)
{
	std::cout << ele << " ";
}

int		main()
{
	std::string	s_array[3] = {"a", "b", "c"};
	size_t		slen = 3;

	int			i_array[2] = {0, 1};
	size_t		ilen = 2;

	double		d_array[2] = {0.1, 1.1};
	size_t		dlen = 2;

	iter(s_array, slen, func_string);
	std::cout << std::endl;
	iter(i_array, ilen, func_template<int>);
	std::cout << std::endl;
	iter(d_array, dlen, func_template<double>);
	std::cout << std::endl;
	return (0);
}
