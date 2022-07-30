#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(const T &container, int num)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), num);

	if (it == container.end())
		throw std::runtime_error("Number not found");
	return (it);
}

#endif
