#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstdbool>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string			name;
		AMateria			*materias[4];
		AMateria			*materia_thrown[100];
		bool				has_space;
		static const int	MAX_UNEQUIP = 100;
	public:
		Character();
		Character(const Character &character);
		Character &operator=(const Character &character);
		virtual ~Character();
		Character(std::string name);
		virtual std::string const	&getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

#endif
