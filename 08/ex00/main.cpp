#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main()
{
	int	nums[] = { 10, 20, 30, 40 };
	std::vector<int>	vec(nums, nums + 4);
	std::list<int>		lst;
	std::deque<int>		deque;

	try
	{
		std::cout << *easyfind(vec, 20) << std::endl;
		std::cout << *easyfind(vec, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "vec  : " << e.what() << '\n';
	}
	try
	{
		lst.push_back(1);
		std::cout << *easyfind(lst, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "list : " << e.what() << '\n';
	}
	try
	{
		deque.push_back(-1);
		std::cout << *easyfind(deque, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "stack: " << e.what() << '\n';
	}
	return (0);
}
