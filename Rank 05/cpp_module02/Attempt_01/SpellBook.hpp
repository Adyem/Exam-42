#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map < std::string, ASpell * > _SpellBook;
		SpellBook(const SpellBook &other);
		SpellBook &operator=(const SpellBook &other);

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &name);
		ASpell *createSpell(std::string const &string);
};

#endif
