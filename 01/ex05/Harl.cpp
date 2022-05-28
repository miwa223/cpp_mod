#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain( std::string level )
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*funcs[])(void) = {&Harl::debug, &Harl::info,
											&Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon ";
	std::cout << "for my 7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years ";
	std::cout << "whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}
