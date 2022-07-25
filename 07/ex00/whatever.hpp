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

template <class T> T &min(T &x, T &y)
{
	if (x < y)
		return (x);
	return (y);
}

template <class T> T &max(T &x, T &y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

#endif
