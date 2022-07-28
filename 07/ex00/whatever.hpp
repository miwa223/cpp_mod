#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <class T> void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <class T> T const &min(T const &x, T const &y)
{
	if (x < y)
		return (x);
	return (y);
}

template <class T> T const &max(T const &x, T const &y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif
