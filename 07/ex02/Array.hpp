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

		T &operator[](unsigned int i);
		unsigned int	size() const;
};

class Sample
{
	public:
		Sample(size_t n = 0);
		~Sample();
		size_t	get_num() const;
		void	set_num(size_t num);
	private:
		size_t	num;
};

void	test_default_constructor();
void	test_complex_type();

#endif
