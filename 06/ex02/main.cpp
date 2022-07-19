#include "Identify.hpp"

int	main()
{
	std::srand((unsigned)std::time(NULL));
	Base *res = generate();

	identify(res);
	identify(*res);
	return (0);
}
