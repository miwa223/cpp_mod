#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<class T> class Array
{
	private:
		unsigned int	n;
		T				*array;

	public:
		Array(unsigned int n = 0);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int i) const;
		unsigned int	size() const;
};

#endif
