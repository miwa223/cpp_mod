#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

bool	Contact::isDigits(std::string &num)
{
	for (size_t i = 0; i < num.length(); i++)
	{
		if (std::isdigit(num[i]) == 0)
			return (false);
	}
	return (true);
}

bool	Contact::isPrints(std::string &str)
{
	size_t	i = 0;

	while (i < str.length())
	{
		if (std::isprint(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

void	Contact::inputContact(int index)
{
	std::string	*contents[5] = {&first_name, &last_name, &nickname,
							&phone_number, &darkest_secret};
	std::string	names[5] = {"first name", "last name", "nickname",
								"phone number", "darkest secret"};
	id = index;
	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << "Type " << names[i] << ": ";
			std::cin >> *contents[i];
			if (i == 3)
			{
				if (isDigits(*contents[i]))
					break;
				std::cout << E_DIGITS << std::endl;
			}
			else
			{
				if (isPrints(*contents[i]))
					break ;
				std::cout << E_PRINTS << std::endl;
			}
		}
	}
}

bool	Contact::isValidIndex(int index)
{
	return (index == id);
}

void	Contact::displaySummary()
{
	std::string	contents[3] = {first_name, last_name, nickname};

	if (std::to_string(id).length() > 10)
		std::cout << std::setfill('.') << std::setw(10) << std::left << id;
	else
		std::cout << std::setfill(' ') << std::setw(10) << std::right << id;
	for (int i = 0; i < 3; i++)
	{
		std::cout << '|';
		if (contents[i].length() > 10)
			std::cout << std::setfill('.') << std::setw(10) << std::left
				<< contents[i].substr(0, 9);
		else
			std::cout << std::setfill(' ') << std::setw(10) << std::right
				<< contents[i];
	}
	std::cout << std::endl;
}

void	Contact::displayContact()
{
	std::string	contents[5] = {first_name, last_name, nickname,
								phone_number, darkest_secret};

	for (int i = 0; i < 5; i++)
		std::cout << contents[i] << std::endl;
}
