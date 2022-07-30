#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <limits>
#include <string>
#include <iostream>

enum	e_OPERATION
{
	ADD,
	ADD_MANY,
	COMPARE,
};

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	nums;

		void	assertion(enum e_OPERATION type, size_t cnt) const;
	public:
		Span(unsigned int N = 0);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		void	addManyNumbers(int *arr, size_t cnt);
		void	addManyNumbers(std::vector<int> vec);
		size_t	shortestSpan();
		size_t	longestSpan();
};

#endif
