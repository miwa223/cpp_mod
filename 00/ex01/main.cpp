#include "phonebook.hpp"

int	main(void)
{
	int			i = 0;
	std::string	cmd;
	PhoneBook	*phonebook;

	phonebook = new PhoneBook();
	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT: ";
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook->add(i++);
		else if (cmd == "SEARCH")
			phonebook->search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << E_CMD << std::endl;
	}
	delete phonebook;
	return (0);
}
