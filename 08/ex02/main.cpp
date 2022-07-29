#include "MutantStack.hpp"
#include <list>

void	test_list_ver();
void	test_const_iterator();
void	test_reverse_iterator();
void	test_const_reverse_iterator();

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	/*
	test_list_ver();
	test_const_iterator();
	test_reverse_iterator();
	test_const_reverse_iterator();
	*/
	return 0;
}

void	test_list_ver()
{
	std::cout << "* test_list_ver *" << std::endl;
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

void	test_const_iterator()
{
	std::cout << "\n* test_const_iterator *" << std::endl;
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>::const_iterator	it = mstack.begin();
	MutantStack<int>::const_iterator	ite = mstack.end();
	for (; it != ite; it++)
		std::cout << *it << std::endl;
}

void	test_reverse_iterator()
{
	std::cout << "\n* test_reverse_iterator *" << std::endl;
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>::reverse_iterator	it = mstack.rbegin();
	MutantStack<int>::reverse_iterator	ite = mstack.rend();
	for (; it != ite; it++)
	{
		std::cout << *it << std::endl;
		*it = 0;
	}
	for (it = mstack.rbegin(); it != ite; it++)
	{
		std::cout << *it << std::endl;
	}
}

void	test_const_reverse_iterator()
{
	std::cout << "\n* test_const_reverse_iterator *" << std::endl;
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator ite = mstack.rend();
	for (; it != ite; it++)
		std::cout << *it << std::endl;
}
