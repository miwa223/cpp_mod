#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <class T, class S, class R>
void	iter(T *array, S len, R (*func)(T &))
{
	for (S i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

void	test_string();
void	test_double();
void	test_instantiated_function_template();
void	func_string(std::string &ele);
int		func_double(double &ele);
template <class T> T	func_template(T &ele);

#endif
