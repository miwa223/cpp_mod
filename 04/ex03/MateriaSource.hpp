#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*m_srcs[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &materia);
		MateriaSource &operator=(const MateriaSource &materia);
		virtual ~MateriaSource();
		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
