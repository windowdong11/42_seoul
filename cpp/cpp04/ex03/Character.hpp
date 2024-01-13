#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "UnequippedManager.hpp"

class Character : public ICharacter
{
private:
	static const int slotSize = 4;
	std::string name;
	AMateria *slot[4];
	UnequippedManager unequippedManager; //! DO NOT COPY THIS (IT OCCURS SEGFAULT)
public:
	Character();
	Character(const Character& rhs);
	Character& operator=(const Character& rhs);
	~Character();

	Character(std::string const & name);

	std::string const & getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif