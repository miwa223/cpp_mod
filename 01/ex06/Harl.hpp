#ifndef _HARL_HPP
#define _HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Harl();
		~Harl();
		void complain( std::string level );
};

void	harlFilter(Harl harl, int level);
int		stoiLevel(std::string level);
int		exitError(void);

#endif
