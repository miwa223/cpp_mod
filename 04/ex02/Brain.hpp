#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		std::string	ideas[100];
		Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		virtual ~Brain();
};

#endif
