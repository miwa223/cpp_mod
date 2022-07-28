#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <class T>
void	iter(T *array, size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <class T>
void	iter(T const *array, size_t len, void (*func)(T const &))
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

#endif
