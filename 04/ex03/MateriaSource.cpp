#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->m_srcs[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &materia)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	this->m_srcs[0] = nullptr;
	*this = materia;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materia)
{
	if (this == &materia)
		return (*this);

	std::cout << "MateriaSource copy assignment operator" << std::endl;

	for (int i = 0; i < 4 && this->m_srcs[i]; i++)
		delete this->m_srcs[i];
	for (int i = 0; i < 4 && materia.m_srcs[i]; i++)
		this->m_srcs[i] = materia.m_srcs[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < 4 && m_srcs[i]; i++)
		delete m_srcs[i];
}

void		MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->m_srcs[i])
		{
			this->m_srcs[i] = m;
			return ;
		}
	}
	std::cerr << "Error: Can't learn anymore" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m_srcs[i] && this->m_srcs[i]->getType() == type)
		{
			return (this->m_srcs[i]->clone());
		}
	}
	std::cerr << "Error: Unknown type" << std::endl;
	return (0);
}
