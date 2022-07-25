#include "Array.hpp"

template<class T> Array<T>::Array(unsigned int n)
{
	this->n = n;
	if (n > 0)
		this->array = new T[n];
	else
		this->array = NULL;
}

template<class T> Array<T>::Array(const Array<T> &other)
{
	this->array = NULL;
	*this = other;
}

template<class T> Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this == &other)
		return (*this);
	this->n = other.n;
	delete [] this->array;
	this->array = new T[other.n];
	for (size_t i = 0; i < other.n; i++)
		this->array[i] = other.array[i];
	return (*this);
}

template<class T> Array<T>::~Array()
{
	delete [] this->array;
}

template<class T> T				&Array<T>::operator[](unsigned int i)
{
	if (i >= this->n)
		throw std::exception();
	return (this->array[i]);
}

template<class T> unsigned int	Array<T>::size() const
{
	return (this->n);
}
