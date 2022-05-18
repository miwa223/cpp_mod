#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; i++)
		contacts[i] = NULL;
}

PhoneBook::~PhoneBook()
{
	int	i = 0;

	while (contacts[i])
		delete contacts[i++];
}

void	PhoneBook::add(int index)
{
	if (!contacts[index % 8])
		contacts[index % 8] = new Contact();
	contacts[index % 8]->inputContact(index);
}

int		PhoneBook::stoiNum(std::string &sindex)
{
	int					num = 0;
	std::istringstream	issindex(sindex);

	for (size_t i = 0; i < sindex.length(); i++)
	{
		if (i == 0 && sindex[i] == '+' && sindex[i + 1])
			continue;
		if (std::isdigit(sindex[i]) == 0)
			return (-1);
	}
	issindex >> num;
	return (num);
}

void	PhoneBook::search()
{
	int			i = 0;
	int			index = 0;
	std::string	sindex;

	if (!contacts[0])
	{
		std::cout << E_NOCONTACT << std::endl;
		return ;
	}
	while (contacts[i])
		contacts[i++]->displaySummary();
	while (1)
	{
		std::cout << "Type the index of the entry to display: ";
		std::cin >> sindex;
		if ((index = stoiNum(sindex)) == -1 || !contacts[index % 8]
			|| !contacts[index % 8]->isValidIndex(index))
			std::cout << E_INDEX << std::endl;
		else
		{
			contacts[index % 8]->displayContact();
			break ;
		}
	}
}
