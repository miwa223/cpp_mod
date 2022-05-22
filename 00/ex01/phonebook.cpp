#include "Phonebook.hpp"
#include "Contact.hpp"

const std::string PhoneBook::E_NOCONTACT = "No contact found. Add a contact first.";
const std::string PhoneBook::E_INDEX = "Index not found. Try again.";
const std::string PhoneBook::E_CMD = "Invalid command.";
const std::string PhoneBook::E_EOF = "Exit by unexpected EOF";

PhoneBook::PhoneBook() : nb_contacts(0)
{
	std::cout << ">> Welcome to our phonebook!\n" << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i] = NULL;
}

PhoneBook::~PhoneBook()
{
	int	i = 0;

	while (i < 8 && contacts[i])
		delete contacts[i++];
	std::cout << "\n>> Have a nice day!" << std::endl;
}

bool	PhoneBook::add()
{
	if (contacts[nb_contacts])
		delete contacts[nb_contacts];
	contacts[nb_contacts] = new Contact();
	if (!contacts[nb_contacts]->inputContact(nb_contacts))
		return (false);
	if (nb_contacts == 7)
		nb_contacts = 0;
	else
		nb_contacts++;
	return (true);
}

int		PhoneBook::stoiNum(std::string &sindex)
{
	std::istringstream	issindex(sindex);
	int					num = 0;
	size_t				i = 0;

	if (sindex[0] == '+')
		i++;
	if (sindex.length() == i + 1 && '0' <= sindex[i] && sindex[i] <= '7')
	{
		issindex >> num;
		return (num);
	}
	return (-1);
}

bool	PhoneBook::search()
{
	int			i = 0;
	int			index = 0;
	std::string	sindex;

	if (!contacts[0])
	{
		std::cerr << PhoneBook::E_NOCONTACT << std::endl;
		return (true);
	}
	while (i < 8 && contacts[i])
		contacts[i++]->displaySummary();
	while (1)
	{
		std::cout << "Type the index of the entry to display: ";
		std::getline(std::cin, sindex);
		if (std::cin.eof())
			return (false);
		if (sindex == "" || (index = stoiNum(sindex)) == -1 || !contacts[index])
			std::cerr << E_INDEX << std::endl;
		else
			break ;
	}
	contacts[index]->displayContact();
	return (true);
}
