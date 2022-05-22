#include "Phonebook.hpp"

bool	operateCmd(std::string &cmd, PhoneBook *phonebook)
{
	if (cmd != "ADD" && cmd != "SEARCH" && cmd != "EXIT" && cmd != "")
		std::cerr << PhoneBook::E_CMD << std::endl;
	else if ((cmd == "ADD" && !phonebook->add())
		|| (cmd == "SEARCH" && !phonebook->search()))
	{
		std::cerr << PhoneBook::E_EOF << std::endl;
		return (false);
	}
	else if (cmd == "EXIT")
		return (false);
	return (true);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cerr << PhoneBook::E_EOF << std::endl;
			break ;
		}
		if (!operateCmd(cmd, &phonebook))
			break ;
	}
	return (0);
}
