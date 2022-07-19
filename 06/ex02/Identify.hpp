#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <string>
#include <iostream>
#include <cstdlib> //srand, rand
#include <ctime> //time
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
