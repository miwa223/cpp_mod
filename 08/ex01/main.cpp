#include "Span.hpp"

void	test_erange();
void	test_ecompare();
void	test_intminmax();
void	test_copy_constructor();
void	test_addManyNumbers();

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	/*
	test_erange();
	test_ecompare();
	test_intminmax();
	test_copy_constructor();
	test_addManyNumbers();
	*/
	return 0;
}

void	test_erange()
{
	std::cout << "\n* test_erange *" << std::endl;
	try
	{
		Span sp = Span(0);
		sp.addNumber(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_ecompare()
{
	std::cout << "\n* test_erange *" << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(0);
		std::cout << "shortest: "<< sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_intminmax()
{
	std::cout << "\n* test_intminmax *" << std::endl;
	try
	{
		Span sp = Span(3);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		sp.addNumber(0);
		std::cout << "shortest: "<< sp.shortestSpan() << std::endl;
		std::cout << "longest : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_copy_constructor()
{
	std::cout << "\n* test_copy_constructor *" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		Span sp2 = sp;
		std::cout << "shortest: "<< sp2.shortestSpan() << std::endl;
		std::cout << "longest : " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_addManyNumbers()
{
	std::cout << "\n* test_addManyNumbers *" << std::endl;
	try
	{
		Span 				sp = Span(100000);
		int					nums[] = {1, 2, 3};
		std::vector<int>	vec_nums(10000, 100);

		sp.addNumber(10);
		sp.addManyNumbers(nums, sizeof(nums) / sizeof(nums[0]));
		sp.addManyNumbers(vec_nums);
		std::cout << "shortest: "<< sp.shortestSpan() << std::endl;
		std::cout << "longest : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
