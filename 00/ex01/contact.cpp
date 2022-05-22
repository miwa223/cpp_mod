#include "Contact.hpp"

const std::string Contact::E_EMPTY = "Empty field not acceptable.";
const std::string Contact::E_DIGITS = "Only Digits are acceptable. Try again.";
const std::string Contact::E_PRINTS = "Only printable characters are acceptable. Try again.";
const std::string Contact::E_ALNUMS = "Only alphabets and numbers are acceptable. Try again.";

Contact::Contact() {}

Contact::~Contact() {}

bool	Contact::isDigits(std::string &num) const
{
	for (size_t i = 0; i < num.length(); i++)
	{
		if (std::isdigit(num[i]) == 0)
			return (false);
	}
	return (true);
}

bool	Contact::isPrints(std::string &str) const
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

bool	Contact::isAlnums(std::string &str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isalnum(str[i]) == 0)
			return (false);
	}
	return (true);
}

bool	Contact::validateInput(int i, std::string &content) const
{
	if (content == "")
		std::cerr << E_EMPTY << std::endl;
	else if (i == 3)
	{
		if (isDigits(content))
			return (true);
		std::cerr << E_DIGITS << std::endl;
	}
	else if (i == 4)
	{
		if (isPrints(content))
			return (true);
		std::cerr << E_PRINTS << std::endl;
	}
	else
	{
		if (isAlnums(content))
			return (true);
		std::cerr << E_ALNUMS << std::endl;
	}
	return (false);
}

bool	Contact::inputContact(int index)
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
			std::getline(std::cin, *contents[i]);
			if (std::cin.eof())
				return (false);
			if (validateInput(i, *contents[i]))
				break ;
		}
	}
	return (true);
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
	std::string	names[5] = {"first name", "last name", "nickname",
								"phone number", "darkest secret"};

	for (int i = 0; i < 5; i++)
		std::cout << names[i] << ": " << contents[i] << std::endl;
}
