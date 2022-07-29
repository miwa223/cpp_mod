#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack &other) { *this = other; };
		MutantStack &operator=(const MutantStack &other)
		{
			(void)other;
			return (*this);
		};
		virtual ~MutantStack() {};

		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		typedef typename std::reverse_iterator<iterator>				reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator>			const_reverse_iterator;

		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };

		const_iterator begin() const { return this->c.begin(); };
		const_iterator end() const { return this->c.end(); };

		reverse_iterator rbegin() { return this->c.rbegin(); };
		reverse_iterator rend() { return this->c.rend(); };

		const_reverse_iterator rbegin() const { return this->c.rbegin(); };
		const_reverse_iterator rend() const { return this->c.rend(); };
};

#endif
